#include "VideoFollower.h"
#include <QHBoxLayout>
#include <QUrl>
#include <QVideoWidget>
#include <QAudioOutput>
#include <QSlider>
#include <QLabel>

VideoFollower::VideoFollower(const std::string& name, const std::string& topic, QWidget *parent)
        : Component(name, topic),
          QWidget(parent),
          Subscriber(name, topic),
          mediaPlayer(nullptr),
          videoWidget(nullptr),
          audioOutput(nullptr),
          volumeSlider(nullptr)
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
    delete videoWidget;
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

    if (!videoWidget) {
        mediaPlayer = new QMediaPlayer();
        audioOutput = new QAudioOutput();
        videoWidget = new QVideoWidget();

        mediaPlayer->setAudioOutput(audioOutput);
        mediaPlayer->setVideoOutput(videoWidget);

        // Slider de Volumen
        volumeSlider = new QSlider(Qt::Horizontal); // Slider horizontal
        volumeSlider->setRange(0, 100); // Rango de 0 a 100 para el slider
        volumeSlider->setValue(80);    // Valor inicial (corresponde a 0.8)

        connect(volumeSlider, &QSlider::valueChanged, this, [this](int value) {
            if (audioOutput) {
                audioOutput->setVolume(static_cast<float>(value) / 100.0f);
            }
        });

        auto* playerLayout = new QVBoxLayout();
        auto* controlsLayout = new QHBoxLayout();

        controlsLayout->addWidget(new QLabel("Volumen:"));
        controlsLayout->addWidget(volumeSlider);

        playerLayout->addWidget(videoWidget);
        playerLayout->addLayout(controlsLayout);

        auto* containerWidget = new QWidget();
        containerWidget->setLayout(playerLayout);

        containerWidget->setAttribute(Qt::WA_DeleteOnClose);

        connect(containerWidget, &QWidget::destroyed, this, [this]() {
            videoWidget = nullptr;
            mediaPlayer = nullptr;
            audioOutput = nullptr;
            volumeSlider = nullptr;
        });

        containerWidget->setWindowTitle("Reproductor de Video - " + QString::fromStdString(getName()));
        containerWidget->resize(800, 600);
        containerWidget->show();
    }

    mediaPlayer->setSource(QUrl(QString::fromStdString(lastUrl)));
    audioOutput->setVolume(static_cast<float>(volumeSlider->value()) / 100.0f);
    mediaPlayer->play();
    
    if (videoWidget && videoWidget->window()) {
        videoWidget->window()->raise();
        videoWidget->window()->activateWindow();
    }
}