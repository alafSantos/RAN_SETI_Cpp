#ifndef BASE_SENSOR_BUFFER
#define BASE_SENSOR_BUFFER

#include <iostream>
#include "../include/SensorData.h"


template <class T>
class BaseSensorBuffer
{
private:
    virtual void store(SensorData<T>& data){
        std::cout << "storing data " << data.getValue() << " from sensor " << data.getID() << std::endl;
    }

    virtual void retrieve(int sensorIdx){
        std::cout << "retrieving data from sensor " << sensorIdx << std::endl;
    }

    void saveBufferToFile(const char* outName);

public:
    void read(const char *fName, const char *outputFile);
};

#endif