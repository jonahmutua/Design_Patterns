#include "ComponentFactory.h"

void ComponentFactory::destroyComponent(IComponent* component)
{
            Mediator::deregisterComponent(component);// TODO derigister component 
            delete component;
}