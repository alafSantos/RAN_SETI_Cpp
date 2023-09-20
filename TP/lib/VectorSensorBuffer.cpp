#include "../include/VectorSensorBuffer.h"
#include <fstream>
#include <iostream>

template class VectorSensorBuffer<int>;
template class VectorSensorBuffer<float>;
template class VectorSensorBuffer<double>;

template <class T>
void VectorSensorBuffer<T>::store(SensorData<T> &data)
{
    this->buffer.push_back(data);
}

template <class T>
void VectorSensorBuffer<T>::retrieve(int sensorIdx)
{
    std::cout << "Buffer size before retrieving data from sensor " << sensorIdx << " is equal to " << this->buffer.size() << std::endl;

    for(auto i = begin(this->buffer); i < end(this->buffer); i++){
        if(i->getID() == sensorIdx)
        {
            this->buffer.erase(i);
            break;
        }
    }

    std::cout << "Buffer size after retrieving data from sensor " << sensorIdx << " is equal to " << this->buffer.size() << std::endl;
}

template <class T>
void VectorSensorBuffer<T>::saveBufferToFile(const char *outName)
{
    std::ofstream outputFileStream(outName);

    if (!outputFileStream.is_open())
    {
        std::cerr << "Error: It was impossible to create the output file | " << outName << std::endl;
        return;
    }

    for(int i = 0; i < this->buffer.size(); i++){
        outputFileStream << "ID: " << this->buffer[i].getID() << " Value: " << this->buffer[i].getValue() << std::endl;
    }

    outputFileStream.close();
}
