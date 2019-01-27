#pragma once

class Room;

class Gate
{
	// serve as arc on the graph
	// this should be stored in `_sta->gatesToNeighbor`
public:
	Gate();
	~Gate();
	double getVelocity() { return _velocity; }
	Room * getFrom() const { return _sta; }
	Room * getDest() const { return _des; }
private:
	Room * _sta;
	Room * _des;
	double _velocity; // the velocity of passing
};
