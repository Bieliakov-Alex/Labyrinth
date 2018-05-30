#pragma once
#include "Node.h"
#include <list>
class LabNode :
	public Node
{
private:
	std::list<Coords> childrens;
	bool is_goal{ false };
	bool is_start{ false };
	int pathToStart{ -1 };
	int pathToGoal{ -1 };
	LabNode() = delete;
public:
	LabNode(const Coords & c, bool is = false, bool ig = false);
	void setPathToStart(int);
	void setPathToEnd(int);
	int getPathToStart() const override;
	int getPathToGoal() const override;
	bool hasChild(const Coords& child) const override;
	void addChild(const Coords& child) override;
	bool isGoal() const override;
	bool isStart() const override;
	std::list<Coords>::const_iterator getChildrensBegin() const;
	std::list<Coords>::const_iterator getChildrensEnd() const;
	~LabNode();
};

