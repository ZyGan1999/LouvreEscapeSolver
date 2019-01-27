#include "Graph.h"
#include <map>
#include <queue>

Graph::Graph()
{
}


Graph::~Graph()
{
}

void Graph::CalcAttractions()
{
	std::map<Gate * , double>_minTimes;
	for (auto rm : _rooms) {
		for (auto neighbor = rm->begin(); neighbor != rm->end(); ++neighbor) {
			// Traversal all the neighbors
			for (auto des : _destinations) {
				double curdesMinTime = minTimeRequired((*neighbor)->getDest(), des);
				if(_minTimes[*neighbor] > curdesMinTime)
				_minTimes[*neighbor] = curdesMinTime;
			}
		}
		while (rm->getPopulation()) {
			Gate * choice = *(rm->begin());
			for (auto neighbor = rm->begin(); neighbor != rm->end(); ++neighbor) {
				if (_minTimes[*neighbor] < _minTimes[choice]) choice = *neighbor;
			}
			rm->setPopulation(rm->getPopulation() - 1);
			if (!choice->getDest()->isExit()) choice->getDest()->setPopulation(choice->getDest()->getPopulation() + 1);
			_minTimes[choice] += 1 / choice->getVelocity();
		}
	}
}

void Graph::TraversalAndMove()
{
	for (auto it : _rooms) {
		// look for 
	}
}

// calculate the time needed from `Room s` to `Room t`
// please note that `s->getCrossTime()` is INCLUDED, `t->getCrossTime()` is EXCLUDED
double Graph::minTimeRequired(Room * s, Room * t)
{
	std::map<Room *, double> d;
	auto comp = [](
		const std::pair<Room *, double>& lhs,
		const std::pair<Room *, double>& rhs)
		-> bool { return lhs.second > rhs.second; };
	//std::priority_queue<
	//	std::pair<Room *, double>,
	//	std::vector<std::pair<Room *, double>>,
	//	decltype(comp)
	//	> q;
	std::priority_queue<
		std::pair<Room *, double>,
		std::vector<std::pair<Room *, double>>,
		decltype(comp)
	> q(comp);
	d[s] = 0;
	q.push(std::make_pair(s, 0));
	while (!q.empty()) {
		auto curRoom = q.top().first;
		auto curD = q.top().second;
		q.pop();
		if (curD > d[curRoom]) continue;
		if (curRoom == t) continue;
		for (const auto edge : *curRoom) {
			auto newRoom = edge->getDest();
			// if `newRoom` is not in the map `d`, 
			// we can regard `d[newRoom]` as infinity
			if (d.find(newRoom) == d.cend()) {
				d[newRoom] = curD + curRoom->getCrossTime();
			}
			else {
				d[newRoom] = std::min(d[newRoom], curD + curRoom->getCrossTime());
			}
			q.push(std::make_pair(newRoom, d[newRoom]));
		}
	}
	return d.find(t) != d.cend() ?
		d[t] : 1e10;
}

bool Graph::isEscapeFinished()
{
	for (auto it : _rooms) {
		if (!it->isEmpty()) {
			return false;
		}
	}
	return true;
}
