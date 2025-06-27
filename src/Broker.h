#ifndef BROKER_H
#define BROKER_H

#include "Topic.h"
#include "Subscriber.h"
#include <vector>
#include <string>

// Intermediario que gestiona los tópicos y las suscripciones.
class Broker {
public:
    // El destructor se encarga de liberar la memoria de los tópicos creados.
    ~Broker();

    Topic* createTopic(const std::string& topicName);
    bool subscribe(Subscriber* sub);

private:
    Topic* findTopic(const std::string& topicName);
    std::vector<Topic*> topics;
};

#endif //BROKER_H