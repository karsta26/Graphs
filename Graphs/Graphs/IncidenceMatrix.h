#pragma once
#include "AdjacencyMatrix.h"

class IncidenceMatrix
{
public:
	IncidenceMatrix();
	// konwersja z macierzy sasiedztwa
	IncidenceMatrix(AdjacencyMatrix& sas);
	~IncidenceMatrix();

	// wypisuje macierz na ekran
	void wypiszMacierz() const;
	int** zwrocMacierz() const
	{
		return _matrix;
	}
	int liczbaWierzcholkow() const
	{
		return _V;
	}
	int liczbaKrawedzi() const
	{
		return _E;
	}
	// rezerwuje pamiec na tablice 
	void zarezerwujPamiec(const int x, const int y);


private:
	// liczba wierzcholkow
	int _V;
	// liczba krawedzi
	int _E;
	// macierz jako tablica
	int** _matrix;
};

