#include "Node.h"



Node::Node(const Coords &c): nodeCoord{c}
{

}

Coords Node::getCoords() const
{
	return nodeCoord;
}


Node::~Node()
{
}
