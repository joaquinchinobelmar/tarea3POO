#include "VideoPublisher.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>

VideoPublisher::VideoPublisher(const std::string& name,
                               Broker& broker,
                               const std::string& topicName,
                               QWidget* parent)
    : QWidget(parent),                // inicializa el widget base
    Publisher(name, broker, topicName) // inicializa el Publisher (que a su vez construye Component)
{
    auto* layout = new QHBoxLayout(this);
    nameLabel = new QLabel(QString::fromStdString(name + " (" + topicName + "): "), this);
    urlField = new QLineEdit(this);
    urlField->setPlaceholderText("Ingrese URL del video y presione Enter");

    layout->addWidget(nameLabel);
    layout->addWidget(urlField);
    setLayout(layout);

    connect(urlField, &QLineEdit::returnPressed,
            this, &VideoPublisher::onUrlEntered);
}

void VideoPublisher::onUrlEntered() {
    const auto url = urlField->text().toStdString();
    if (!url.empty()) {
        emit videoURLPublished(url);



        //publishNewEvent(url);
        //urlField->clear();
    }
    urlField->clear();
}
