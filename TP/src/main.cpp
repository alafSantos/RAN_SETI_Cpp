#include "../include/SensorData.h"
#include "../include/BaseSensorBuffer.h"
#include "../include/VectorSensorBuffer.h"
#include "../include/ListSensorBuffer.h"
#include <iostream>

#define QUESTION_5
#define VECTOR

int main(int argc, char *argv[])
{
#ifndef QUESTION_5
    SensorData<int> *sensor = new SensorData(2, 34);

    std::cout << sensor->getValue() << std::endl;
    std::cout << sensor->getID() << std::endl;

    BaseSensorBuffer<int> bsb;
    bsb.read("sensors.txt", "outputBase.txt");

    VectorSensorBuffer<int> vsb;
    vsb.read("sensors.txt", "outputVector.txt");

    ListSensorBuffer<int> lsb;
    lsb.read("sensors.txt", "outputList.txt");

    delete sensor;
#else
#ifdef VECTOR
    VectorSensorBuffer<float> vsb;
    vsb.read("largedata.txt", "outputVector.txt");
#else
    ListSensorBuffer<float> lsb;
    lsb.read("largedata.txt", "outputList.txt");
#endif
#endif

    return 0;
}