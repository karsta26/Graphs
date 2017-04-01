#pragma once
#include <string>

class AdjacencyList;

class AdjacencyMatrix
{
public:
	// konstruktor domyslny
	AdjacencyMatrix();
	// konstruktor macierzy z tablicy 
	AdjacencyMatrix(int** matrixOrigin, int sizeOfMatrix);
	// konstruktor macierzy z pliku
	AdjacencyMatrix(const char* fileName);
	// konstruktor macierzy ze stringu
	AdjacencyMatrix(const std::string strMatrix);
	// konwersja z listy sasiedztwa
	AdjacencyMatrix(AdjacencyList* Adjacencylist);
	// destruktor usuwa tablice dynamiczna
	~AdjacencyMatrix();
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
	// zwraca macierz sasiedztwa
	int** getMatrix() const
	{return _matrix;}
	// rezerwuje pamiec na tablice 
	void setMemory(const int x, const int y);
	// liczy krawedzie w grafie
	void countEdges();
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

