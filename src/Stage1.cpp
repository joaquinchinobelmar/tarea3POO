#include "Stage1.h"
#include <QHBoxLayout>

Stage1::Stage1(QWidget *parent) : QWidget(parent) {
    // Primero, se crea el Broker
    broker = new Broker();

    // Luego, se crean los componentes (publicador y suscriptor)
    std::string topicName = "Nombre_del_topico";
    videoPublisher = new VideoPublisher("Publicador", *broker, topicName, this);
    videoFollower = new VideoFollower("Suscriptor_Juanito", topicName, this);

    // Se realiza la suscripción
    broker->subscribe(videoFollower);

    // Se Configura el layout de la ventana principal
    auto* mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(videoPublisher);
    mainLayout->addWidget(videoFollower);
    setLayout(mainLayout);
}

Stage1::~Stage1() {
    // Qt se encarga de los widgets hijos (videoPublisher, videoFollower), pero como el broker no es un QObject hijo, se debe borrar manualmente
    delete broker;
}