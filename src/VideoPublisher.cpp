#include "VideoPublisher.h"
#include <QHBoxLayout>

VideoPublisher::VideoPublisher(const std::string& name, Broker& broker, const std::string& topic, QWidget *parent)
        : Component(name, topic),
          QWidget(parent),
          Publisher(name, broker, topic) {

    // Crear la interfaz de usuario
    auto* layout = new QHBoxLayout(this);
    nameLabel = new QLabel(QString::fromStdString(name + " (" + topic + "): "), this);
    urlField = new QLineEdit(this);
    urlField->setPlaceholderText("Ingrese URL del video y presione Enter");

    layout->addWidget(nameLabel);
    layout->addWidget(urlField);
    setLayout(layout);

    // Conecta la señal 'returnPressed' (con Enter) del QLineEdit a nuestro slot de onUrlEntered
    connect(urlField, &QLineEdit::returnPressed, this, &VideoPublisher::onUrlEntered);
}

void VideoPublisher::onUrlEntered() {
    std::string url = urlField->text().toStdString();
    if (!url.empty()) {
        publishNewEvent(url); // Publica el evento
        urlField->clear(); // Limpia el campo de texto
    }
}