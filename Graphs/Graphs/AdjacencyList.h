#pragma once
#include "IncidenceMatrix.h"
#include <vector>
#include <list>

class AdjacencyList
{
public:
	// konstruktor
	AdjacencyList(const int numOfVertex);
	// konwersja z macierzy incydencji
	AdjacencyList(IncidenceMatrix& incMatrix);
	// zwraca liste
	std::vector< std::list<int> > getList() const
	{
		return _list;
	}
	// zwraca liste jako string
	std::string getString() const;
	// dodaje krawedz'
	bool addEdge(const int vertexOne, const int vertexTwo);

private:
	// lista
	std::vector< std::list<int> > _list;
	// liczba wierzcholkow
	int _V;
	// liczba krawedzi
	int _E;

};

