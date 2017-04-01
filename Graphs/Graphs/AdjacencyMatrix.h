#pragma once

#include <string>

class AdjacencyList;

class AdjacencyMatrix
{
public:
	AdjacencyMatrix();
	// konstruktor macierzy z pliku
	AdjacencyMatrix(const char* nazwaPliku);
	// konwersja z listy sasiedztwa
	AdjacencyMatrix(AdjacencyList* listaSasiedztwa);
	// destruktor usuwa tablice dynamiczna
	~AdjacencyMatrix();
	// wypisuje macierz na ekran
	void wypiszMacierz() const;
	int liczbaWierzcholkow() const
	{
		return _V;
	}
	int liczbaKrawedzi() const
	{
		return _E;
	}
	int** zwrocMacierz() const
	{return _matrix;}
	// wczytuje dane z klawiatury
	void wczytajDane();
	// rezerwuje pamiec na tablice 
	void zarezerwujPamiec(const int x, const int y);
	// liczy krawedzie w grafie
	void policzKrawedzie();

private:
	// liczba wierzcholkow
	int _V;
	// liczba krawedzi
	int _E;
	// macierz jako tablica
	int** _matrix;
};

