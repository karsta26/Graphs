#pragma once
#include "IncidenceMatrix.h"
#include <vector>
#include <list>

class AdjacencyList
{
public:
	// konstruktor domyslny
	AdjacencyList();
	// konwersja z macierzy incydencji
	AdjacencyList(IncidenceMatrix& incMatrix);
	// zwraca liste
	std::vector< std::list<int> > getList() const
	{
		return _list;
	}
	// zwraca liste jako string
	std::string getString() const;

private:
	std::vector< std::list<int> > _list;

};

