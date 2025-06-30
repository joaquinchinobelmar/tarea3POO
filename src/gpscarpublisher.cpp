#include "gpscarpublisher.h"
#include <QFile>
#include <QTextStream>
#include <QTimer>
#include <QDebug>

GPSCarPublisher::GPSCarPublisher(const QString& name, const QString& topicName, Broker& broker)
    : QObject(),
    Publisher(name.toStdString(), broker, topicName.toStdString()),
    currentIndex(0),
    timeAccumulator(0.0f)
{
    connect(&timer, &QTimer::timeout, this, &GPSCarPublisher::publishNextPosition);
}

void GPSCarPublisher::loadPositionsFromFile(const QString& filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "No se pudo abrir el archivo:" << filePath;
        return;
    }

    positions.clear();
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(" ");
        if (parts.size() == 3) {
            GPSPosition pos;
            pos.time = parts[0].toInt();
            pos.x = parts[1].toFloat();
            pos.y = parts[2].toFloat();
            positions.append(pos);
        }
    }

    currentIndex = 0;
    timeAccumulator = 0.0f;

    if (!positions.isEmpty()) {        //esto inicia el temporizador
        timer.start(1000);
    }
}

void GPSCarPublisher::publishNextPosition() {
    if (currentIndex >= positions.size())
        return;

    GPSPosition pos = positions[currentIndex];
    emit positionPublished(pos.time, pos.x, pos.y); //emita la señakl

    currentIndex++;
}
