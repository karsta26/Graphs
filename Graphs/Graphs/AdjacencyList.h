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
	std::vector< std::list<int> > getList() const
	{
		return _V;
	}
	// czyta dane z klawiatury
	void setDataFromKeyboard();
	std::string getString() const;

private:
	std::vector< std::list<int> > _V;

};

