#pragma once
//Абстрактный класс для работы с узлами графа, представляющего лабиринт
#include "Coords.h"
class Node
{
private:
	Coords nodeCoord;
public:
	///<summary><c>getCoords</c> - метод, который возвращает координаты текущего узла</summary>
	///<returns>Координаты текущего узла</returns>
	Coords getCoords() const;

	///<summary><c>getPathToStart</c> - метод, который возвращает минимальное количество узлов, которые лежат между ним и стартом</summary>
	///<returns>Минимальное количество узлов между этим узлом и стартом</returns>
	virtual int getPathToStart() const = 0;

	///<summary><c>getPathToGoal</c> - метод, который возвращает минимальное количество узлов, которые лежат между ним и целью</summary>
	///<returns>Минимальное количество узлов между этим узлом и целью</returns>
	virtual int getPathToGoal() const = 0;

	///<summary><c>hasChild</c> - метод, который возвращает <c>true</c>, если у него есть потомок с такими координатами, иначе возвращает <c>false</c></summary>
	///<param name='child'>Координаты искомого потомка</param>
	///<returns><c>true</c>, если у него есть потомок с такими координатами, иначе возвращает <c>false</c></returns>
	virtual bool hasChild(const Coords& child) const = 0;

	///<summary><c>hasParent</c> - метод, который возвращает <c>true</c>, если у него есть потомок с такими координатами, иначе возвращает <c>false</c></summary>
	///<param name='parent'>Координаты искомого предка</param>
	///<returns><c>true</c>, если у него есть потомок с такими координатами, иначе возвращает <c>false</c></returns>
	virtual bool hasParent(const Coords& parent) const = 0;

	///<summary><c>addChild</c> - метод, который добавляет координаты потомка текущего узла</summary>
	///<param name='child'>Координаты добавляемого потомка</param>
	virtual void addChild(const Coords& child) = 0;

	///<summary><c>addParent</c> - метод, который добавляет координаты предка текущего узла</summary>
	///<param name='parent'>Координаты добавляемого предка</param>
	virtual void addParent(const Coords& parent) = 0;

	///<summary><c>findBestWayToGoal</c> - метод, который возвращает координаты потомка, который ближе всего к цели. Если сам является целью, возвращает свои коориданты</summary>
	///<returns>Возвращает координаты узла потомка, который ближе всего к цели. Если узел является целью, он возвращает свои координаты.</returns>
	virtual Coords findBestWayToGoal() const = 0;

	///<summary><c>findBestWayToStart</c> - метод, который возвращает координаты потомка, который ближе всего к старту. Если сам является стартом, возвращает свои коориданты</summary>
	///<returns>Возвращает координаты узла потомка, который ближе всего к старту. Если узел является стартом, он возвращает свои координаты.</returns>
	virtual Coords findBestWayToStart() const = 0;

	///<summary><c>isGoal</c> - метод, который возвращает <c>true</c>, если узел является целью. Иначе возвращает <c>false</c>.</summary>
	///<returns>Возвращает <c>true</c>, если узел является целью. Иначе возвращает <c>false</c>.</returns>
	virtual bool isGoal() const = 0;

	///<summary><c>isGoal</c> - метод, который возвращает <c>true</c>, если узел является началом. Иначе возвращает <c>false</c>.</summary>
	///<returns>Возвращает <c>true</c>, если узел является началом. Иначе возвращает <c>false</c>.</returns>
	virtual bool isStart() const = 0;

	Node();
	~Node();
};

