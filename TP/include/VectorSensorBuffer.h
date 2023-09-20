#ifndef VECTOR_SENSOR_BUFFER
#define VECTOR_SENSOR_BUFFER

#include "../include/BaseSensorBuffer.h"
#include "../include/SensorData.h"
#include <vector>

template <class T>
class VectorSensorBuffer : public BaseSensorBuffer<T>
{
private:
    std::vector<SensorData<T>> buffer;
    void store(SensorData<T> &data);
    void retrieve(int sensorIdx);
    void saveBufferToFile(const char *outName);
};

#endif