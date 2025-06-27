#ifndef TOPIC_H
#define TOPIC_H

#include <string>
#include <vector>
#include "Subscriber.h"

class Topic {
public:
    explicit Topic(std::string name);

    void subscribe(Subscriber* sub);
    void notifySubscribers(const std::string& message);
    bool hasThisName(const std::string& name) const;
    std::string getName() const;

private:
    std::string topicName;
    std::vector<Subscriber*> subscribers;
};

#endif //TOPIC_H