#pragma once
#include "Room.h"
#include "Gate.h"
#include <vector>
#include <map>
class Graph
{
public:
	Graph();
	~Graph();
	void CalcAttractions();
	void TraversalAndMove();
	double Dijstra(Room s, Room t);
	bool isEscapeFinished();
private:
	vector<Room> _rooms;
	vector<Room> _destinations;
	vector<Gate> _gates;
	map<Room, map<Room, Gate> > _room2gate;
};

