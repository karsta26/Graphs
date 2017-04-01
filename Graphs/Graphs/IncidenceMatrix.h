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
	int** getMatrix() const
	{
		return _matrix;
	}
	int getV() const
	{
		return _V;
	}
	int getE() const
	{
		return _E;
	}
	// rezerwuje pamiec na tablice 
	void setMemory(const int x, const int y);
	std::string getString() const;


private:
	// liczba wierzcholkow
	int _V;
	// liczba krawedzi
	int _E;
	// macierz jako tablica
	int** _matrix;
};

