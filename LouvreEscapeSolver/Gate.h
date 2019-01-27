#pragma once
#include "Room.h"
class Gate
{
// serve as arc on the graph
public:
	Gate();
	~Gate();
	double getVelocity() { return _velocity; }
private:
	Room * _sta;
	Room * _des;
	double _velocity; // the velocity of passing
};

