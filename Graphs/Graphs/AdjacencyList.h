#pragma once
#include "IncidenceMatrix.h"
#include <vector>
#include <list>

class AdjacencyList
{
public:
	AdjacencyList();
	// konwersja z macierzy incydencji
	AdjacencyList(IncidenceMatrix& mac);
	void wypiszListe() const;
	std::vector< std::list<int> > zwrocListe() const
	{
		return _V;
	}
	// czyta dane z klawiatury
	void wczytajDane();

private:
	std::vector< std::list<int> > _V;

};

