#ifndef FORECAST_CONDITION_H_
#define FORECAST_CONDITION_H_

#include<iostream>
using namespace std;

#include"Observer.h"



class ForecastCondition:public Observer
{
public:
	ForecastCondition()
		:m_currenPressure(0.0),m_lastPressure(0.0)
	{

	}
	~ForecastCondition(){}

	void update(float temperature, float humidity, float pressure)
	{
		m_lastPressure = m_currenPressure;
		m_currenPressure = pressure;
		display();
	}

	void display()
	{
		cout.setf(ios::showpoint);
		cout.precision(3);
		if (m_currenPressure > m_lastPressure)
		{
			cout << "Improving weather on the day!";
		}
		else if(m_currenPressure<m_lastPressure)
		{
			cout << "Watch out for cooler,rainy weather";
		}
		else
		{
			cout << "More of the same";
		}
		cout << endl;

	}

private:
	float m_currenPressure;
	float m_lastPressure;

	ForecastCondition(const ForecastCondition&);
	ForecastCondition& operator=(const ForecastCondition&);
};

#endif

