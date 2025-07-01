#include "Publisher.h"
#include <iostream>

Publisher::Publisher(const std::string& name, Broker& broker, const std::string& topicName)
        : Component(name, topicName) {
    this->topic = broker.createTopic(topicName);
}

void Publisher::publishNewEvent(const std::string& message) {
    if (topic) {
        topic->notifySubscribers(message);
    } else {
        std::cout << "Error: Publicador " << getName() << " no tiene topico asignado." << std::endl;
    }
}

Topic* Publisher::getTopic() const {
    return topic;
}