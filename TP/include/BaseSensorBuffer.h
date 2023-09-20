#ifndef BASE_SENSOR_BUFFER
#define BASE_SENSOR_BUFFER

#include "../include/SensorData.h"

template <class T>
class BaseSensorBuffer
{
private:
    virtual void store(SensorData<T>& data);
    virtual void retrieve(int sensorIdx);
    virtual void saveBufferToFile(const char* outName);

public:
    void read(const char *fName, const char *outputFile);
};

#endif