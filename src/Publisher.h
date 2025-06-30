#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "Component.h"
#include "Broker.h"
#include "Topic.h"

class Publisher : public Component {
public:

    Publisher(const std::string& name,
              Broker& broker,
              const std::string& topicName);

    void publishNewEvent(const std::string& message);
    Topic* getTopic() const;

private:
    Topic* topic;
};

#endif
