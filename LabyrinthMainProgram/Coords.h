#pragma once
// Класс, который реализует хранение координат узлов лабиринта
class Coords
{
private:
	unsigned int x{ 0 };
	unsigned int y{ 0 };
public:
	Coords();
	Coords(const unsigned int, const unsigned int);
	Coords(const Coords&);
	unsigned int getX() const;
	unsigned int getY() const;
	~Coords();
};

