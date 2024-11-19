#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <algorithm>
#include <vector>

// // Forward declaration of IComponent and SensorData
class IComponent;
struct SensorData;

/// @brief manages Registration , deregistration and notifications of components 
class  Mediator
{
public:
    // Register a new component
    static void registerComponent(IComponent* component);

    // Deregister an existing component
    static void deregisterComponent(IComponent* component);

    // Notify all registered components except the sender
    static void notifyAll(const SensorData& data, IComponent* sender);

private:
    // Shared state (Monostate pattern)
    static std::vector<IComponent*>& getComponents();

};

#endif