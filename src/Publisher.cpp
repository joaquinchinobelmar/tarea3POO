#include "Publisher.h"


Publisher::Publisher(const std::string& name,
                     Broker& broker,
                     const std::string& topicName)
    : Component(name, topicName),
    topic(broker.createTopic(topicName))
{}

void Publisher::publishNewEvent(const std::string& message) {
    if (topic) topic->notifySubscribers(message);
}

Topic* Publisher::getTopic() const {
    return topic;
}
