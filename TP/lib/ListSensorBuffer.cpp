#include "ListSensorBuffer.h"
#include <fstream>
#include <iostream>

template class ListSensorBuffer<int>;
template class ListSensorBuffer<float>;
template class ListSensorBuffer<double>;

template <class T>
void ListSensorBuffer<T>::store(SensorData<T> &data)
{
    this->buffer.push_back(data);
}

template <class T>
void ListSensorBuffer<T>::retrieve(int sensorIdx)
{
    std::cout << "Buffer size before retrieving data from sensor " << sensorIdx << " is equal to " << this->buffer.size() << std::endl;

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
void ListSensorBuffer<T>::saveBufferToFile(const char *outName)
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
