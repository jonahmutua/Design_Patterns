#ifndef ICOMPONENT_H
#define ICOMPONENT_H

#include "SensorData.h"
#include <string>
#include <iostream> 
#include <thread>
#include <chrono>
#include "Mediator.h"



/// @brief  Interface class .
/// @brief This interface allows components to be both producer and consumer
class IComponent
{
    public:
         virtual ~IComponent() = default;
         virtual void produce() = 0;
         virtual void consume(const SensorData& data ) = 0;
};

/// @brief This class can both produce and consume data
class ProducerConsumer : public IComponent
{
    public:
        ProducerConsumer( std::string componentName ) : 
                        _componentName{componentName},  _count{10}
        {

        }
        void produce() override
        {
            SensorData data;
            data.value = _count;
            std::cout<< "[" << _componentName <<"] produced: " << data.value << std::endl;
        }
        void consume(const SensorData& data ) override
        {
            std::cout<< "[" << _componentName <<"] consumed: " << data.value << std::endl;
        }

        ~ProducerConsumer()
        {
            std::cout<< "[" << _componentName <<"] destroyed. " << std::endl;
        }

      // Method to start the thread
       void startThread() {
        // Launch the thread and call the lambda that sleeps for 2 seconds
        std::thread thread(&ProducerConsumer::sleepForTwoSeconds, this);  // Pass `this` to use member function
        thread.detach(); // Detach the thread to allow it to run independently
    }

    private:
        std::string _componentName;
        int         _count;

        // Function that the thread will execute
    void sleepForTwoSeconds() {
        while(1){
        SensorData data;
        std::cout << "[" << _componentName << "] thread started, sleeping for 2 seconds..." << std::endl;
        // Sleep for 2 seconds
        std::this_thread::sleep_for(std::chrono::seconds(2));
        
        data.value = _count++;
        std::cout << "[" << _componentName << "] Thread woke up after 2 seconds!" << std::endl;
        std::cout <<"[" + _componentName + "] Produced value: " << data.value << std::endl;
        Mediator::notifyAll(data, this); // Notify all compnents 
        }
    }

};

#endif