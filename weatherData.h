#ifndef _WEATHERDATA_H_
#define _WEATHERDATA_H_

#include<assert.h>

#include<list>
using namespace::std;

#include"subject.h"
#include"Observer.h"


class WeatherData :public Subject
{
public:
	WeatherData()
		:m_temperature(0.0),m_humidity(0.0),m_pressure(0.0)
	{
	}

	void registerObserver(Observer* o)
	{
		assert(o);
		m_observers.push_back(o);
	}
	void removeObserver(Observer* o)
	{
		m_observers.remove(o);
	}

	void notifyObserver()const
	{
		for (list<Observer*>::const_iterator it = m_observers.begin(); it != m_observers.end(); ++it)
		{
			Observer* obj = *it;
			obj->update(m_temperature, m_humidity, m_pressure);
		}
	}
	~WeatherData(){}

	void measurementsChanged()
	{
		notifyObserver();
	}

	void setMeasurements(float temperature, float humitity, float pressure)
	{
		m_temperature = temperature;
		m_humidity = humitity;
		m_pressure = pressure;
		measurementsChanged();
	}

private:
	float m_temperature;
	float m_humidity;
	float m_pressure;
	
	list<Observer*>m_observers;

	WeatherData(const WeatherData&);
	WeatherData& operator=(const WeatherData&);
};




#endif // !_WEATHERDATA_H_

