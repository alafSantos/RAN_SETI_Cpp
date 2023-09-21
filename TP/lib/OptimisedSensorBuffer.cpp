#include "OptimisedSensorBuffer.h"
#include <fstream>
#include <iostream>
#include <algorithm> // find

template class OptimisedSensorBuffer<int>;
template class OptimisedSensorBuffer<float>;
template class OptimisedSensorBuffer<double>;

template <class T>
void OptimisedSensorBuffer<T>::store(SensorData<T> &data)
{
    this->buffer.push_back(data);
}

template <class T>
bool found(SensorData<T> i) {
  return true;//(i.getID() == ;
}


template <class T>
void OptimisedSensorBuffer<T>::retrieve(int sensorIdx)
{
    std::cout << "Buffer size before retrieving data from sensor " << sensorIdx << " is equal to " << this->buffer.size() << std::endl;

    // int *p = std::find(this->buffer.begin(), this->buffer.end(), )

    for (auto i = this->buffer.begin(); i != this->buffer.end(); i++)
    {
        if (i->getID() == sensorIdx)
        {
            this->buffer.erase(i);
            break;
        }
    }

    std::cout << "Buffer size after retrieving data from sensor " << sensorIdx << " is equal to " << this->buffer.size() << std::endl;
}

template <class T>
void OptimisedSensorBuffer<T>::saveBufferToFile(const char *outName)
{
    std::ofstream outputFileStream(outName);

    if (!outputFileStream.is_open())
    {
        std::cerr << "Error: It was impossible to create the output file | " << outName << std::endl;
        return;
    }

    for (auto i : this->buffer)
    {
        outputFileStream << "ID: " << i.getID() << " Value: " << i.getValue() << std::endl;
    }

    outputFileStream.close();
}
