#include "Topic.h"

Topic::Topic(std::string name) : topicName(std::move(name)) {}

void Topic::subscribe(Subscriber* sub) {
    subscribers.push_back(sub);
}

void Topic::notifySubscribers(const std::string& message) {
    for (Subscriber* sub : subscribers) {
        if (sub) {
            sub->update(message);
        }
    }
}

bool Topic::hasThisName(const std::string& name) const {
    return topicName == name;
}

std::string Topic::getName() const {
    return topicName;
}