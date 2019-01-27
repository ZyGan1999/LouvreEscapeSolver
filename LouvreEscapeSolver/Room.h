#pragma once
#include <list>
#include <vector>
using namespace std;
class Room
{
	// serve as nodes on the graph
public:
	Room();
	~Room();
	bool isEmpty() { return _population == 0; }
	void setAttraction(double a) { _attraction = a; }
	int getPopulation() { return _population; }
	std::vector<Room * >::const_iterator getNeighborsbegin() const { return _neighborRooms.begin(); }
	std::vector<Room * >::const_iterator getNeighborsend() const { return _neighborRooms.end(); }
	std::vector<Room * >::const_iterator getNeighborscbegin() const { return _neighborRooms.cbegin(); }
	std::vector<Room * >::const_iterator getNeighborscend() const { return _neighborRooms.cend(); }
private:
	double _attraction; // the attraction of the room
	int _population; // current number of people in the room
	vector<Room * > _neighborRooms; // rooms that are neighbor
};

