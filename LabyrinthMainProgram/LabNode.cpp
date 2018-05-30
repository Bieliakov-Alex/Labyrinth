#include "LabNode.h"

LabNode::LabNode(const Coords & c, bool is = false, bool ig = false)
	: Node(c),
	is_start{ is },
	is_goal{ ig }
{
}

void LabNode::setPathToStart(int pts)
{
	if (pts < 0)
	{
		return;
	}
	else
	{
		pathToStart = pts;
	}
}

void LabNode::setPathToEnd(int pte)
{
	if (pte < 0)
	{
		return;
	}
	else
	{
		pathToGoal = pte;
	}
}

int LabNode::getPathToStart() const
{
	return pathToStart;
}

int LabNode::getPathToGoal() const
{
	return pathToGoal;
}

bool LabNode::hasChild(const Coords & child) const
{
	for (auto i = childrens.begin(); i != childrens.end(); i++)
	{
		if (*i == child)
		{
			return true;
		}
	}
	return false;
}

void LabNode::addChild(const Coords & child)
{
	childrens.push_back(child);
}

bool LabNode::isGoal() const
{
	return is_goal;
}

bool LabNode::isStart() const
{
	return is_start;
}

std::list<Coords>::const_iterator LabNode::getChildrensBegin() const
{
	return childrens.begin();
}

std::list<Coords>::const_iterator LabNode::getChildrensEnd() const
{
	return childrens.end();
}

LabNode::~LabNode()
{
}
