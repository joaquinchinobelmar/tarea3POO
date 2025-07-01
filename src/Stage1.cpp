#include "Stage1.h"
#include <QHBoxLayout>
#include <QFileDialog>

Stage1::Stage1(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Simulador Publicador-Suscriptor");

    // Primero, se crea el Broker
    broker = new Broker();

    // Luego, se crean los nombres de los tópicos y sus componentes
    std::string videoTopic = "Video";
    std::string gpsTopic = "GPS";
    videoPublisher = new VideoPublisher("Publicador Video", *broker, videoTopic, this);
    gpsPublisher = new GPSCarPublisher("Publicador GPS", *broker, gpsTopic, this);
    videoFollower = new VideoFollower("Suscriptor Video", videoTopic, this);
    carTracker = new CarTracker("Rastreador Auto", gpsTopic);

    // Se realiza la suscripción
    broker->subscribe(videoFollower);
    broker->subscribe(carTracker);

    // Se Configura el layout de la ventana principal
    auto* mainLayout = new QHBoxLayout(this);
    auto* leftLayout = new QVBoxLayout();  // Layout para publicadores
    auto* rightLayout = new QVBoxLayout(); // Layout para suscriptores en la ventana principal

    // Añadir publicadores a la izquierda
    leftLayout->addWidget(videoPublisher);
    leftLayout->addWidget(gpsPublisher);
    leftLayout->addStretch();

    // Añadir suscriptores (solo el de video) a la derecha
    rightLayout->addWidget(videoFollower);
    rightLayout->addStretch();

    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    setLayout(mainLayout);

    // (Lógica de GPS) abrir el diálogo para seleccionar el archivo de GPS
    QString gpsFilePath = QFileDialog::getOpenFileName(this, "Seleccione Archivo de Posiciones GPS", "", "Text Files (*.txt);;All Files (*)");

    if (!gpsFilePath.isEmpty()) {
        gpsPublisher->loadFileAndStart(gpsFilePath);
    }

    // Mostrar la ventana del CarTracker
    carTracker->show();
}

Stage1::~Stage1() {
    delete broker;
}