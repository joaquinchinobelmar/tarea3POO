#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

// Clase base para todos los componentes del sistema.
class Component {
public:
    // Constructor virtual por defecto para permitir polimorfismo
    virtual ~Component() = default;

    // Métodos para obtener el nombre y el tópico del componente
    std::string getName() const;
    std::string getTopicName() const;

protected:
    // Constructor protegido para ser llamado solo por clases hijas
    Component(std::string componentName, std::string topicName);

    std::string name;
    std::string topicName;
};

#endif //COMPONENT_H