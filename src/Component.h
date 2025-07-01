#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

class Component {
public:
    // Constructor virtual por defecto para permitir polimorfismo
    virtual ~Component() = default;

    std::string getName() const;
    std::string getTopicName() const;

protected:
    Component(std::string componentName, std::string topicName);

    std::string name;
    std::string topicName;
};

#endif //COMPONENT_H