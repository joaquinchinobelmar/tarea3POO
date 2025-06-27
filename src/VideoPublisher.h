#ifndef VIDEOPUBLISHER_H
#define VIDEOPUBLISHER_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include "Publisher.h"

// Widget que permite al usuario ingresar una URL y publicarla
class VideoPublisher : public QWidget, public Publisher {
    Q_OBJECT // Macro necesaria para clases con señales y slots

public:
    VideoPublisher(const std::string& name, Broker& broker, const std::string& topic, QWidget *parent = nullptr);

private slots:
    // Slot que se activa cuando el usuario presiona el Enter en el campo de texto
    void onUrlEntered();

private:
    QLineEdit* urlField;
    QLabel* nameLabel;
};

#endif //VIDEOPUBLISHER_H