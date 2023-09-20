#include "../include/SensorData.h"
#include "../include/BaseSensorBuffer.h"
#include "../include/VectorSensorBuffer.h"
#include "../include/ListSensorBuffer.h"
#include "../include/OptimisedSensorBuffer.h"
#include <iostream>

#define QUESTION_6
// #define QUESTION_5
// #define VECTOR

int main(int argc, char *argv[])
{
#ifndef QUESTION_6
#ifndef QUESTION_5
    SensorData<int> *sensor = new SensorData(2, 34);

    std::cout << sensor->getValue() << std::endl;
    std::cout << sensor->getID() << std::endl;

    BaseSensorBuffer<int> bsb;
    bsb.read("inputFiles/sensors.txt", "outputFiles/outputBase.txt");

    VectorSensorBuffer<int> vsb;
    vsb.read("inputFiles/sensors.txt", "outputFiles/outputVector.txt");

    ListSensorBuffer<int> lsb;
    lsb.read("inputFiles/sensors.txt", "outputFiles/outputList.txt");

    delete sensor;
#else
#ifdef VECTOR
    VectorSensorBuffer<float> vsb;
    vsb.read("inputFiles/largedata.txt", "outputFiles/outputVector.txt");
#else
    ListSensorBuffer<float> lsb;
    lsb.read("inputFiles/largedata.txt", "outputFiles/outputList.txt");
#endif
#endif
#else
    OptimisedSensorBuffer<float> osb;
    osb.read("inputFiles/largedata.txt", "outputFiles/outputOptimised.txt");
#endif

    return 0;
}