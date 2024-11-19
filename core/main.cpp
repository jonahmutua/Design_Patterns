#include <iostream>
using namespace std;
#include <thread>
#include <chrono>
#include "ComponentFactory.h"




int main()
{ 

    // Create components dynamically using the FactoryComponent
    IComponent*  gps       = ComponentFactory::createComponent<ProducerConsumer>("Gps");
    IComponent*  gpio      = ComponentFactory::createComponent<ProducerConsumer>("Gpio");
    IComponent*  bluetooth = ComponentFactory::createComponent<ProducerConsumer>("Bluetooth");

    IComponent*   wifi = ComponentFactory::createComponent<WIFI::Wifi>("Wifi");

    // state the gps thread ... 
    dynamic_cast<ProducerConsumer*>(gps)->startThread();
   
    // delete gpio component 
    ComponentFactory::destroyComponent(gpio);

     // Sleep in the main thread for a bit to ensure the spawned thread runs
    std::this_thread::sleep_for(std::chrono::seconds(3));

    // Delete gps and bluetooth
    ComponentFactory::destroyComponent(gps);
    ComponentFactory::destroyComponent(bluetooth);

    std::cout << "Main thread finished." << std::endl;  
    
    return 0;
}