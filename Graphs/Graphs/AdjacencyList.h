#pragma once
#include "IncidenceMatrix.h"
#include <vector>
#include <list>
#include "IncidenceMatrix.h"

class AdjacencyList
{
public:
	AdjacencyList();
	// konwersja z macierzy incydencji
	AdjacencyList(IncidenceMatrix& mac);
	void wypiszListe() const;
	std::vector< std::list<int> > zwrocListe()
	{
		return _V;
	}
	// czyta dane z klawiatury
	void wczytajDane();

private:
	std::vector< std::list<int> > _V;

};

