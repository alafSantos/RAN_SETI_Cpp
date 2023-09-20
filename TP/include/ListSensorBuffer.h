#ifndef LIST_SENSOR_BUFFER
#define LIST_SENSOR_BUFFER

#include "../include/BaseSensorBuffer.h"
#include "../include/SensorData.h"
#include <list>

template <class T>
class ListSensorBuffer : public BaseSensorBuffer<T>
{
private:
    std::list<SensorData<T>> buffer;

    void store(SensorData<T> &data);
    void retrieve(int sensorIdx);
    void saveBufferToFile(const char *outName);
};


#endif