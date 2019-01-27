#include "Graph.h"



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
		for (auto i = it.getNeighborsbegin(); i != it.getNeighborsend(); ++i) {
			totalVelocity += _room2gate[it][**i].getVelocity();
		}
		minTime += it.getPopulation() / totalVelocity;
		double attrac;
		//attrac = f(minTime);
		it.setAttraction(attrac);
	}
}

void Graph::TraversalAndMove()
{
	for (auto it : _rooms) {
		// look for 
	}
}

double Graph::Dijstra(Room s, Room t)
{

	int min, Final[maxSize], k, *a;//final用来存储到各节点的最短距离;*a作为返回值
	int  kn[maxSize];//kn是否找到最短路径
	for (int i = 0; i < numVertxnode; i++)//
	{
		if (vertxnode[i].data == q)
		{
			v2 = vertxnode[i];
		}
		if (vertxnode[i].data == p)
		{
			v = vertxnode[i];
			temp = v.firstEdge;
			Final[i] = 0;
			kn[i] = 1;
		}
		else {
			Final[i] = INFINITY;
			kn[i] = 0;
		}
	}
	if (v.data == '0' || (v2.data == '0'&&choose == 2))
	{
		cout << "输入点有误！" << endl;
		return;
	}
	else
	{
		while (temp)
		{
			Final[temp->adjvex] = temp->weight;
			temp = temp->next;
		}
	}

	min = INFINITY;
	for (int i = 0; i < numVertxnode; i++)//主循环
	{
		while (temp)
		{
			if (kn[temp->adjvex] == 0 && temp->weight + min < Final[temp->adjvex])
			{
				Final[temp->adjvex] = temp->weight + min;
			}
			temp = temp->next;
		}
		min = INFINITY;
		for (int j = 0; j < numVertxnode; j++)//查找到v最近的点
		{
			if (min > Final[j] && Final[j] != 0 && kn[j] == 0)
			{
				min = Final[j];
				k = j;//记录min对于节点序号
			}
		}
		kn[k] = 1;//找到最近节点 
		temp = vertxnode[k].firstEdge;
	}
}

bool Graph::isEscapeFinished()
{
	for (auto it : _rooms) {
		if (!it.isEmpty()) {
			return false;
		}
	}
	return true;
}
