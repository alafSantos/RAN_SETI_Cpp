#include "SensorData.h"

template class SensorData<int>;
template class SensorData<float>;
template class SensorData<double>;

template <class T>
SensorData<T> &SensorData<T>::operator=(SensorData<T> const &sensor)
{
    this->ID = sensor.getID();
    this->value = sensor.getValue();
    return *this;
}

template <class T>
int SensorData<T>::getID() const
{
    return this->ID;
}

template <class T> T SensorData<T>::getValue() const
{
    return this->value;
}
