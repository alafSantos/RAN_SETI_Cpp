#include "../include/BaseSensorBuffer.h"
#include <fstream>
#include <iostream>

template class BaseSensorBuffer<int>;
template class BaseSensorBuffer<float>;
template class BaseSensorBuffer<double>;

template <class T>
void BaseSensorBuffer<T>::store(SensorData<T> &data)
{
    std::cout << "storing data " << data.getValue() << " from sensor " << data.getID() << std::endl;
}

template <class T>
void BaseSensorBuffer<T>::retrieve(int sensorIdx)
{
    std::cout << "retrieving data from sensor " << sensorIdx << std::endl;
}

template <class T>
void BaseSensorBuffer<T>::saveBufferToFile(const char *outName)
{
    std::ofstream outputFileStream(outName);

    if (!outputFileStream.is_open())
    {
        std::cerr << "Error: It was impossible to create the output file | " << outName << std::endl;
        return;
    }

    outputFileStream << "I am just a base buffer, I did not save any data actually. Sorry, human";

    outputFileStream.close();
}

template <class T>
void BaseSensorBuffer<T>::read(const char *fName, const char *outputFile)
{
    std::ifstream inputFile(fName);
    if (!inputFile.is_open())
    {
        std::cerr << "Error: It was impossible to open the file | " << fName << std::endl;
        return;
    }

    int data, id, value;
    while (true)
    {
        inputFile >> data;
        if (inputFile.eof())
            break;

        if (!data)
        {
            inputFile >> id;
            inputFile >> value;
            SensorData<T> sensor(id, value);
            this->store(sensor);
        }
        else if (data == 1)
        {
            inputFile >> id;
            this->retrieve(id);
        }
    }

    this->saveBufferToFile(outputFile);

    inputFile.close();
    std::cout << "The reading process has been finalised" << std::endl;
}
