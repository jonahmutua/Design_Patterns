#ifndef COMPONENTFACTORY_H
#define COMPONENTFACTORY_H

#include <string>
#include "Mediator.h"
#include "IComponent.h"
#include "Wifi.h"


/// @brief This class dynamically creates and deletes component
class ComponentFactory
{
    public:
       template<typename T>
       static IComponent* createComponent(const std::string& name)
        {
            T* component = new T(name);
            Mediator::registerComponent( component);  //TODO register component
            return component;
        }

        static void destroyComponent(IComponent* component);
       
};


#endif