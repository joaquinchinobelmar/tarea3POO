#ifndef VIDEOPUBLISHER_H
#define VIDEOPUBLISHER_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include "Publisher.h"

//para la etapa 4.4 con respecto a la 4.2 el codigo tiene cambios incompletos, como mencione se me olvido commitear la 4.3 al repo


class VideoPublisher : public QWidget, public Publisher {
    Q_OBJECT

public:
    VideoPublisher(const std::string& name, Broker& broker, const std::string& topicName, QWidget* parent = nullptr);

signals:
    void videoURLPublished(const std::string& url);

private slots:
    void onUrlEntered();

private:
    QLineEdit* urlField;
    QLabel* nameLabel;
};

#endif //VIDEOPUBLISHER_H
