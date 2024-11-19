#include "Wifi.h"
#include "SensorData.h"
#include <iostream>

namespace WIFI{

WIFI::Wifi::Wifi(const std::string &componentName) : _componentName{componentName}
{

}

void WIFI::Wifi::produce()
{
}

void WIFI::Wifi::consume(const SensorData &data)
{
    std::cout<< "["<< _componentName <<"] consumed: " << data.value <<std::endl;

}

WIFI::Wifi::~Wifi()
{
     std::cout<< "[" << _componentName <<"] destroyed. " << std::endl;
}


} // Namespace WIFI