#ifndef _OBSERVER_H_
#define _OBSERVER_H_

class Observer
{
public:
	virtual ~Observer() = 0 {};
	virtual void update(float, float, float) = 0;

};

#endif // !_OBSERVER_H_

