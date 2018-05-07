#include "Node.h"



Node::Node(const Coords &c): nodeCoord{c}
{

}

Coords Node::getCoords() const
{
	return nodeCoord;
}


bool Node::operator==(const Node & n)
{
	return this->getCoords()==n.getCoords();
}

bool Node::operator!=(const Node & n)
{
	return !(*this==n);
}

Node::~Node()
{
}
