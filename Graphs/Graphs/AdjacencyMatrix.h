#pragma once
#include <string>

class AdjacencyList;

class AdjacencyMatrix
{
public:
	AdjacencyMatrix();
	// konstruktor macierzy z pliku
	AdjacencyMatrix(const char* fileName);
	// konstruktor macierzy ze stringu
	AdjacencyMatrix(const std::string strMatrix);
	// konwersja z listy sasiedztwa
	AdjacencyMatrix(AdjacencyList* Adjacencylist);
	// destruktor usuwa tablice dynamiczna
	~AdjacencyMatrix();
	// wypisuje macierz na ekran
	void wypiszMacierz() const;
	int getV() const
	{
		return _V;
	}
	int getE() const
	{
		return _E;
	}
	int** getMatrix() const
	{return _matrix;}
	// wczytuje dane z klawiatury
	void setDateFromKeyboard();
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

