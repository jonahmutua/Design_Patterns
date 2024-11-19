#include  "Mediator.h"
#include  "IComponent.h"

void Mediator::registerComponent(IComponent* component)
 {
        getComponents().push_back(component);
 }

 void Mediator::deregisterComponent(IComponent* component) {
        auto& components = getComponents();
        components.erase(std::remove(components.begin(), components.end(), component), components.end());
    }

void Mediator::notifyAll(const SensorData& data, IComponent* sender) 
{
        for (auto* component : getComponents()) {
            if (component != sender) {
                component->consume(data);
            }
        }
}

std::vector<IComponent*>& Mediator::getComponents() 
{
     static std::vector<IComponent*> components;
     return components;
}