#include "VideoFollower.h"
#include <QHBoxLayout>

VideoFollower::VideoFollower(const std::string& name, const std::string& topic, QWidget *parent)
        : Component(name, topic),
          QWidget(parent),
          Subscriber(name, topic) {

    auto* layout = new QHBoxLayout(this);
    nameLabel = new QLabel(QString::fromStdString(getName() + " (" + getTopicName() + "): "), this);
    videoButton = new QPushButton("Esperando video...", this);
    videoButton->setEnabled(false); // Deshabilitado hasta recibir la primera URL

    layout->addWidget(nameLabel);
    layout->addWidget(videoButton);
    setLayout(layout);
}

void VideoFollower::update(const std::string& message) {
    // Cuando llega una nueva URL, se actualiza el texto del botón y se habilita.
    videoButton->setText(QString::fromStdString(message));
    if (!videoButton->isEnabled()) {
        videoButton->setEnabled(true);
    }
}