#include "Broker.h"
#include <iostream>

Broker::~Broker() {
    for (Topic* t : topics) {
        delete t;
    }
    topics.clear();
}

Topic* Broker::findTopic(const std::string& topicName) {
    for (Topic* t : topics) {
        if (t->hasThisName(topicName)) {
            return t;
        }
    }
    return nullptr;
}

Topic* Broker::createTopic(const std::string& topicName) {
    Topic* existingTopic = findTopic(topicName);
    if (existingTopic == nullptr) {
        existingTopic = new Topic(topicName);
        topics.push_back(existingTopic);
    }
    return existingTopic;
}

bool Broker::subscribe(Subscriber* sub) {
    Topic* targetTopic = findTopic(sub->getTopicName());
    if (targetTopic != nullptr) {
        targetTopic->subscribe(sub);
        return true;
    } else {
        std::cout << "Error: Topico '" << sub->getTopicName() << "' no existe. Suscripcion fallida para " << sub->getName() << std::endl;
        return false;
    }
}