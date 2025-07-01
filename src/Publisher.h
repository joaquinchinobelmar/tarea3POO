#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "Component.h"
#include "Broker.h"

class Publisher : public virtual Component {
public:
    void publishNewEvent(const std::string& message);

protected:
    Publisher(const std::string& name, Broker& broker, const std::string& topicName);
    Topic* getTopic() const;

private:
    Topic* topic;
};

#endif //PUBLISHER_H