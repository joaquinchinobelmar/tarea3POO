#include "CarTracker.h"
#include <QVBoxLayout>
#include <QString>
#include <QStringList>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QBrush>

CarTracker::CarTracker(const std::string& name, const std::string& topic, QWidget *parent)
        : Component(name, topic),
          QWidget(parent, Qt::Window),
          Subscriber(name, topic)
{
    // Configuración de la ventana
    setWindowTitle(QString::fromStdString("Car Tracker: " + name + ", Topic: " + topic));

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 500, 500);

    view = new QGraphicsView(scene, this);
    view->setBackgroundBrush(QBrush(Qt::white)); // Fondo blanco
    view->setRenderHint(QPainter::Antialiasing); // Para que el círculo se vea suave

    // Creación del círculo que representa el auto
    const double R = 8.0; // Radio del círculo
    carCircle = new QGraphicsEllipseItem(0, 0, 2 * R, 2 * R);
    carCircle->setPos(0, 0); // Posición inicial
    carCircle->setBrush(Qt::red); // Color rojo
    carCircle->setPen(Qt::NoPen); // Sin borde
    scene->addItem(carCircle);

    telemetryLabel = new QLabel("Esperando datos de posición...", this);
    telemetryLabel->setAlignment(Qt::AlignCenter);
    telemetryLabel->setStyleSheet("font-size: 14px; padding: 5px; background-color: #f0f0f0;");

    // Configura el layout
    auto* layout = new QVBoxLayout(this);
    layout->addWidget(view); // La vista gráfica ocupa la mayor parte del espacio
    layout->addWidget(telemetryLabel); // La etiqueta va abajo
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);
    setLayout(layout);

    resize(502, 550); // Ajustar tamaño de la ventana
}

void CarTracker::update(const std::string& message) {
    QString qMessage = QString::fromStdString(message);
    QStringList parts = qMessage.split(' ');

    if (parts.size() >= 3) {
        bool ok1, ok2, ok3;
        double time = parts[0].toDouble(&ok1);
        double x = parts[1].toDouble(&ok2);
        double y = parts[2].toDouble(&ok3);

        if (ok1 && ok2 && ok3) {
            QString labelText = QString::asprintf("t: %.1f, x: %.1f, y: %.1f", time, x, y);
            telemetryLabel->setText(labelText);

            // El origen (0,0) del círculo es su esquina superior izquierda, se le resta el radio para que el 'centro' del círculo quede en (x,y).
            const double R = carCircle->boundingRect().width() / 2.0;
            carCircle->setPos(x - R, y - R);
        }
    }
}