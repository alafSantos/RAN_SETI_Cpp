#ifndef SENSOR_DATA
#define SENSOR_DATA

template <class T>
class SensorData
{
private:
    int ID;
    T value;

public:
    SensorData(){};
    SensorData(int id, T v) : ID(id), value(v){};
    SensorData(const SensorData<T> &sensor) : ID(sensor.getID()), value(sensor.getValue()){};

    SensorData<T> &operator=(SensorData<T> const &sensor);
    int getID() const;
    T getValue() const;
};
#endif