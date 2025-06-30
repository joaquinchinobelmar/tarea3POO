#include "Stage1.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "gpscarpublisher.h"
#include "gpscarsubscriber.h"
//#include "VideoPublisher.h"
//#include "VideoFollower.h"


//habia avanzado para la 4.4 sin subir al repo la 4.3, por si ves cambios raros en algunos archivos (como el VideoFollower y VideoPublisher)
//y por si ves muchas cosas comentadas xddd


Stage1::Stage1(QWidget *parent) : QWidget(parent) {

    broker = new Broker();



    //ESTA PARTE ES PARA EL TEMA DEL GPS
    std::string topicName = "GPS_topic";
    GPSCarPublisher* gpsCarPublisher= new GPSCarPublisher("Publicador_GPS", QString::fromStdString(topicName), *broker);
    gpscarsubscriber* gpsCarSubscriber= new gpscarsubscriber(this);



    //AQUI SERIA EL TEMA DEL VIDEO
    //videoPublisher= new VideoPublisher("Publicador_Video", *broker, QString::fromStdString(topicName));
    //videoFollower= new VideoFollower("Suscriptor_Video", QString::fromStdString(topicName), this);




    connect(gpsCarPublisher, &GPSCarPublisher::positionPublished, gpsCarSubscriber, &gpscarsubscriber::updatePosition);     //se hace la sub

    //connect(videoPublisher, &VideoPublisher::videoURLPublished, videoFollower, &VideoFollower::update);      //vidio



    //en el repo esta un txt llamado posiciones.txt, modifica el directorio por el tuyo (donde dejes el txt)
    gpsCarPublisher->loadPositionsFromFile("/Users/benjamin/Desktop/tarea3poo/posiciones.txt");     //conexion con el .txt




    // se configura el layout de la ventana principal
    auto* mainLayout = new QHBoxLayout(this);

    //mainLayout->addWidget(gpsCarPublisher);       no hay que mostrar el publicador

    mainLayout->addWidget(gpsCarSubscriber);

    setLayout(mainLayout);
}


Stage1::~Stage1() {
    delete broker;
}
