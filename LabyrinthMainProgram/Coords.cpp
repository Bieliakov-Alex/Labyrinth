#include "Coords.h"



Coords::Coords()
{
}

Coords::Coords(const unsigned int x, const unsigned int y) : x{ x },
y{ y }
{
}

Coords::Coords(const Coords & c)
{
	x = c.x;
	y = c.y;
}

unsigned int Coords::getX() const
{
	return x;
}

unsigned int Coords::getY() const
{
	return y;
}


Coords::~Coords()
{
}
