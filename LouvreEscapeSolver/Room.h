#pragma once
#include "Gate.h"
#include <list>
#include <vector>

class Room
{
	// serve as nodes on the graph
public:
	Room();
	~Room();
	bool isEmpty() const { return _population == 0; }
	bool isExit() const { return _isExit; }
	double getAttraction() const { return _attraction; }
	double getCrossTime() const { return _crossTime; }
	void setAttraction(double a) { _attraction = a; }
	int getPopulation() { return _population; }
	void setPopulation(int population) { _population = population; }
	std::vector<Gate * >::iterator begin() { return _gatesToNeighbor.begin(); }
	std::vector<Gate * >::iterator end() { return _gatesToNeighbor.end(); }
	std::vector<Gate * >::const_iterator cbegin() const { return _gatesToNeighbor.cbegin(); }
	std::vector<Gate * >::const_iterator cend() const { return _gatesToNeighbor.cend(); }
private:
	double _attraction; // the attraction of the room
	double _crossTime; // the time needed to go through this room
	bool _isExit; // set this flag to TRUE if this is one of the exits
	int _population; // current number of people in the room
	std::vector<Gate * > _gatesToNeighbor; // gates to rooms that are neighbor
};
