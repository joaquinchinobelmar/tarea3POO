#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "Component.h"
#include <string>

class Subscriber : public virtual Component {
public:
    virtual void update(const std::string& message) = 0;

protected:
    Subscriber(const std::string& name, const std::string& topic)
            : Component(name, topic) {}
};

#endif //SUBSCRIBER_H