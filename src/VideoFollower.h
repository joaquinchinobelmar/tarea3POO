#ifndef VIDEOFOLLOWER_H
#define VIDEOFOLLOWER_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "Subscriber.h"
#include <QMediaPlayer>
class QVideoWidget;
class QAudioOutput;
class QPushButton;
class QLabel;
class QSlider;

// Widget que se suscribe a un topico de video y muestra la última URL en un botón
class VideoFollower : public QWidget, public Subscriber {
    Q_OBJECT

public:
    VideoFollower(const std::string& name, const std::string& topic, QWidget *parent = nullptr);
    ~VideoFollower() override;

    void update(const std::string& message) override;


private slots:
    void onVideoButtonClicked();

private:
    QPushButton* videoButton;
    QLabel* nameLabel;

    std::string lastUrl;       // Guarda la última URL recibida
    QMediaPlayer* mediaPlayer; // El reproductor principal
    QVideoWidget* videoWidget; // El widget donde se muestra el video
    QAudioOutput* audioOutput; // El componente para el sonido
    QSlider* volumeSlider;     // El componente el slider del volumen
};

#endif //VIDEOFOLLOWER_H