#pragma once
/*
Класс, описывающий лабиринт
*/

#include "LabNode.h"
#include <vector>
#include <list>

using namespace std;

class Labyrinth
{
private:
	vector<LabNode> nodes;
public:
	void addNode(const Coords& coords, const list<Coords> childrens, bool is = false, bool ig =  false);
	LabNode& getNode(const Coords& coords);
	bool countStart();
	bool countEnd();
	Labyrinth();
	~Labyrinth();
};

