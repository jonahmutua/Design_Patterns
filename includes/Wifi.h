#ifndef WIFI_H
#define WIFI_H
#include "IComponent.h"
#include <string>

namespace WIFI{
    class Wifi : public IComponent
    {
        public:
            Wifi() = delete;  //Disallow defualt  construction
            Wifi(const std::string& componentName);
            void produce() override;
            void consume(const SensorData& data) override;

            ~Wifi();
        private:
            std::string _componentName{};
    };
    
} // namespace WIFI

#endif // WIFI_H