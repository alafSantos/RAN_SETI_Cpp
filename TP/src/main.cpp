#include "../include/SensorData.h"
#include "../include/BaseSensorBuffer.h"
#include "../include/VectorSensorBuffer.h"
#include <iostream>

int main(int argc, char *argv[]){
    SensorData<int> *sensor = new SensorData(2, 34);

    std::cout << sensor->getValue() << std::endl;
    std::cout << sensor->getID() << std::endl;

    BaseSensorBuffer<int> bsb;
    bsb.read("sensors.txt", "outputBase.txt");

    VectorSensorBuffer<int> vsb;
    vsb.read("sensors.txt", "outputVector.txt");

    delete sensor;
    return 0;
}