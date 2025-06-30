#ifndef VIDEOFOLLOWER_H
#define VIDEOFOLLOWER_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "Subscriber.h"
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QAudioOutput>
class QVideoWidget;
class QAudioOutput;


//para la etapa 4.4 con respecto a la 4.2 el codigo tiene cambios incompletos, como mencione se me olvido commitear la 4.3 al repo



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
};

#endif //VIDEOFOLLOWER_H
