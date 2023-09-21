#ifndef OPTIMISED_SENSOR_BUFFER
#define OPTIMISED_SENSOR_BUFFER

#include "BaseSensorBuffer.h"
#include "SensorData.h"
#include <list>

template <class T>
class OptimisedSensorBuffer : public BaseSensorBuffer<T>
{
private:
    std::list<SensorData<T>> buffer;

    void store(SensorData<T> &data);
    void retrieve(int sensorIdx);
    void saveBufferToFile(const char *outName);
};


#endif