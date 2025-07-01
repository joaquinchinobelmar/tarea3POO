#include "GPSCarPublisher.h"
#include <QHBoxLayout>
#include <QLocale>

GPSCarPublisher::GPSCarPublisher(const std::string& name, Broker& broker, const std::string& topic, QWidget* parent)
        : Component(name, topic),
          QWidget(parent),
          Publisher(name, broker, topic)
{
    // Configuración de la UI
    auto* layout = new QHBoxLayout(this);
    setLayout(layout);
    gpsDataLabel = new QLabel("Seleccione un archivo para iniciar GPS...", this);
    layout->addWidget(new QLabel(QString::fromStdString(name + " ("+topic+"): "), this));
    layout->addWidget(gpsDataLabel);

    // Configuración del Timer
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &GPSCarPublisher::reportPosition);
}

GPSCarPublisher::~GPSCarPublisher() {
    if (dataFile.isOpen()) {
        dataFile.close();
    }
}

bool GPSCarPublisher::loadFileAndStart(const QString& filePath) {
    dataFile.setFileName(filePath);
    if (!dataFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        gpsDataLabel->setText("Error al abrir el archivo.");
        return false;
    }
    fileStream.setDevice(&dataFile);

    if (readNextPointFromFile()) { // Lee el primer punto
        prevX = nextX; prevY = nextY; prevTime = nextTime;
        currentTime = prevTime;

        if (readNextPointFromFile()) { // Lee el segundo punto
            secondDataPointAvailable = true;
        } else {
            // Solo hay un punto, lo publicamos y terminamos.
            QString dataString = QString::asprintf("%.1f %.1f %.1f", prevTime, prevX, prevY);
            gpsDataLabel->setText(dataString);
            publishNewEvent(dataString.toStdString());
            return true;
        }
    } else {
        gpsDataLabel->setText("Archivo vacío o formato incorrecto.");
        return false;
    }

    timer->start(1000);
    return true;
}

bool GPSCarPublisher::readNextPointFromFile() {
    if (!fileStream.atEnd()) {
        QString line = fileStream.readLine();
        QStringList parts = line.split(' ');
        if (parts.size() >= 3) {
            bool ok1, ok2, ok3;
            nextTime = parts[0].toDouble(&ok1);
            nextX = parts[1].toDouble(&ok2);
            nextY = parts[2].toDouble(&ok3);
            return ok1 && ok2 && ok3;
        }
    }
    return false;
}

void GPSCarPublisher::reportPosition() {
    if (currentTime > nextTime && secondDataPointAvailable) {
        prevTime = nextTime;
        prevX = nextX;
        prevY = nextY;
        if (!readNextPointFromFile()) {
            secondDataPointAvailable = false;
        }
    }

    double currentX, currentY;
    double t_interval = nextTime - prevTime;

    if (t_interval <= 0 || !secondDataPointAvailable) {
        currentX = prevX;
        currentY = prevY;
        if (currentTime >= prevTime && !secondDataPointAvailable) {
            timer->stop();
            dataFile.close();
            gpsDataLabel->setText(QString::asprintf("%.1f %.1f %.1f (Final)", prevTime, prevX, prevY));
            publishNewEvent(QString::asprintf("%.1f %.1f %.1f", prevTime, prevX, prevY).toStdString());
            return;
        }
    } else {
        double ratio = (currentTime - prevTime) / t_interval;
        currentX = prevX + (nextX - prevX) * ratio;
        currentY = prevY + (nextY - prevY) * ratio;
    }

    QString dataString = QString::asprintf("%.1f %.1f %.1f", currentTime, currentX, currentY);
    gpsDataLabel->setText(dataString);
    publishNewEvent(dataString.toStdString());

    currentTime += 1.0;
}