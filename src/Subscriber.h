#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "Component.h"
#include <string>

// Clase base abstracta para todos los suscriptores
class Subscriber : public virtual Component {
public:
    // Método virtual puro, asi, toda clase hija DEBE implementarlo
    // es invocado cuando el tópico publica un nuevo mensaje
    virtual void update(const std::string& message) = 0;

protected:
    Subscriber(const std::string& name, const std::string& topic)
            : Component(name, topic) {}
};

#endif //SUBSCRIBER_H