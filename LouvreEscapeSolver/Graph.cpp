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
	for (auto it : _rooms) {
		double minTime = 32768;
		for (auto de : _destinations) {
			// Dijkstra for all the destinations
			double curTime;
			//curTime = Dijkstra(it, de);
			if (curTime < minTime) {
				minTime = curTime;
			}
		}
		double totalVelocity = 0;
		for (auto i : *it) {
			totalVelocity += i->getVelocity();
		}
		minTime += it->getPopulation() / totalVelocity;
		double attrac;
		//attrac = f(minTime);
		it->setAttraction(attrac);
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
	std::priority_queue<
		std::pair<Room *, double>,
		std::vector<std::pair<Room *, double>>,
		decltype(comp)
		> q;
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
