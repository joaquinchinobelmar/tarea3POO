#include "VideoFollower.h"
#include <QHBoxLayout>
#include <QUrl>
#include <QVideoWidget>
#include <QAudioOutput>

VideoFollower::VideoFollower(const std::string& name, const std::string& topic, QWidget *parent)
        : Component(name, topic),
          QWidget(parent),
          Subscriber(name, topic),
          mediaPlayer(nullptr),
          videoWidget(nullptr),
          audioOutput(nullptr)
{
    auto* layout = new QHBoxLayout(this);
    nameLabel = new QLabel(QString::fromStdString(getName() + " (" + getTopicName() + "): "), this);
    videoButton = new QPushButton("Esperando video...", this);
    videoButton->setEnabled(false);

    layout->addWidget(nameLabel);
    layout->addWidget(videoButton);
    setLayout(layout);

    connect(videoButton, &QPushButton::clicked, this, &VideoFollower::onVideoButtonClicked);
}

VideoFollower::~VideoFollower() {
    delete mediaPlayer;
    delete videoWidget;
    delete audioOutput;
}

void VideoFollower::update(const std::string& message) {
    // Guarda la URL para usarla al hacer clic
    lastUrl = message;

    QUrl url(QString::fromStdString(message));
    videoButton->setText("Ver Video: " + url.fileName());

    if (!videoButton->isEnabled()) {
        videoButton->setEnabled(true);
    }
}

void VideoFollower::onVideoButtonClicked() {
    if (lastUrl.empty()) {
        return; // No hacer nada si no hay URL
    }

    if (!mediaPlayer) {
        mediaPlayer = new QMediaPlayer(this);
        audioOutput = new QAudioOutput(this);
        videoWidget = new QVideoWidget();

        mediaPlayer->setAudioOutput(audioOutput);
        mediaPlayer->setVideoOutput(videoWidget);
    }

    // Asignamos la URL al reproductor
    mediaPlayer->setSource(QUrl(QString::fromStdString(lastUrl)));
    audioOutput->setVolume(0.8); // Volumen de 0.0 a 1.0

    // Configuración para mostrar la ventana del video
    videoWidget->setWindowTitle("Reproductor de Video - " + QString::fromStdString(getName()));
    videoWidget->resize(800, 600);
    videoWidget->show();

    mediaPlayer->play();
}