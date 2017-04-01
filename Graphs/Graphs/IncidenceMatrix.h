#pragma once
#include "AdjacencyMatrix.h"

class IncidenceMatrix
{
public:
	// konstruktor domyslny
	IncidenceMatrix();
	// konwersja z macierzy sasiedztwa
	IncidenceMatrix(AdjacencyMatrix& sas);
	// usuwa pamiec zaalokowana dynamicznie
	~IncidenceMatrix();
	// zwraca macierz incydencji
	int** getMatrix() const
	{
		return _matrix;
	}
	// zwraca liczbe wierzcholkow
	int getV() const
	{
		return _V;
	}
	// zwraca liczbe krawedzi
	int getE() const
	{
		return _E;
	}
	// rezerwuje pamiec na tablice 
	void setMemory(const int x, const int y);
	// zwraca macierz jako string
	std::string getString() const;


private:
	// liczba wierzcholkow
	int _V;
	// liczba krawedzi
	int _E;
	// macierz jako tablica
	int** _matrix;
};

