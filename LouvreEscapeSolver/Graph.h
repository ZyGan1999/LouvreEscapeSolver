#pragma once
#include "Room.h"

class Graph
{
public:
	Graph();
	~Graph();
	void CalcAttractions();
	void TraversalAndMove();
	double minTimeRequired(Room * s, Room * t);
	bool isEscapeFinished();
private:
	std::vector<Room *> _rooms;
	std::vector<Room *> _destinations;
};

