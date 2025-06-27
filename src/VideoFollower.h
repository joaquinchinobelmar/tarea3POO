#ifndef VIDEOFOLLOWER_H
#define VIDEOFOLLOWER_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "Subscriber.h"

// Widget que se suscribe a un topico de video y muestra la última URL en un botón
class VideoFollower : public QWidget, public Subscriber {
    Q_OBJECT

public:
    VideoFollower(const std::string& name, const std::string& topic, QWidget *parent = nullptr);

    // Implementación del método virtual puro de Subscriber
    void update(const std::string& message) override;

private:
    QPushButton* videoButton;
    QLabel* nameLabel;
};

#endif //VIDEOFOLLOWER_H