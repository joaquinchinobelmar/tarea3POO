#include "Component.h"
#include <utility>

Component::Component(std::string componentName, std::string topicName)
        : name(std::move(componentName)), topicName(std::move(topicName)) {}

std::string Component::getName() const {
    return name;
}

std::string Component::getTopicName() const {
    return topicName;
}