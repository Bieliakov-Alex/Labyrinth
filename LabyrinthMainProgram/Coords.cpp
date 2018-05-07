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

bool Coords::operator==(const Coords & n)
{
	return this->getX()==n.getX()&&this->getY()==n.getY();
}

bool Coords::operator!=(const Coords & n)
{
	return !(*this==n);
}


Coords::~Coords()
{
}
