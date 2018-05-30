#include "Labyrinth.h"



void Labyrinth::addNode(const Coords& coords, const list<Coords> childrens, bool is = false, bool ig = false)
{
	nodes.push_back(LabNode(coords, is, ig));
	for (auto i = childrens.begin(); i != childrens.end(); i++)
	{
		this->getNode(coords).addChild(*i);
	}
	for (auto i = nodes.begin(); i != nodes.end(); i++)
	{
		for (auto j = childrens.begin(); j != childrens.end(); j++)
		{
			if (i->getCoords() == *j)
			{
				i->addChild(coords);
			}
		}
	}
	if (is)
	{
		this->getNode(coords).setPathToStart(0);
	}
	if (ig)
	{
		this->getNode(coords).setPathToEnd(0);
	}
}
//adfasd;fkljase;dfkja;sdklfja;lskdjf
LabNode& Labyrinth::getNode(const Coords & coords)
{
	for (auto i = nodes.begin(); i != nodes.end(); i++)
	{
		if (i->getCoords() == coords)
		{
			return *i;
		}
	}
	throw - 1;
}

bool Labyrinth::countStart()
{
	bool result = false;
	// найти старт

	//итератор на стартовый узел
	auto start = nodes.end();
	for (auto i = nodes.begin(); i != nodes.end(); i++)
	{
		if (i->isStart())
		{
			result = true;
			start = i;
			break;
		}
	}
	if (result)
	{
		//создаем список узлов, которым нужно назначить путь к старту

		//список пустых узлов
		list<Coords> emptyNodes;		
		for (auto i = nodes.begin(); i != nodes.end(); i++)
		{
			if (i != start)
			{
				emptyNodes.push_back(i->getCoords());
			}
		}

		//присваиваем соседним со стартвым узлом узлам значение 1.
		for (auto i = getNode(start->getCoords()).getChildrensBegin(); i != getNode(start->getCoords()).getChildrensEnd(); i++)
		{
			this->getNode(*i).setPathToStart(1);
			emptyNodes.remove(*i);
		}

		//остальным узлам присваеваем минимальное значение из возможных
		while (!emptyNodes.empty())
		{
			for (auto i = emptyNodes.begin(); i != emptyNodes.end(); i++)
			{
				for (auto j = getNode(*i).getChildrensBegin(); j != getNode(*i).getChildrensEnd(); j++)
				{
					if (getNode(*j).getPathToStart() != -1)
					{
						if (getNode(*i).getPathToStart() == -1 || getNode(*i).getPathToStart() > getNode(*j).getPathToStart() + 1)
						{
							getNode(*i).setPathToStart(getNode(*j).getPathToStart() + 1);
						}
					}
				}
				if (getNode(*i).getPathToStart() != -1)
				{
					break;
				}
			}
			//emptyNodes
		}
	}
	return result;
}

Labyrinth::Labyrinth()
{
}


Labyrinth::~Labyrinth()
{
}
