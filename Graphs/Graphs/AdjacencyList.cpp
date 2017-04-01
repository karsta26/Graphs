#include "AdjacencyList.h"

#include <iostream>
#include <cstdlib>

using namespace std;

AdjacencyList::AdjacencyList()
{}

AdjacencyList::AdjacencyList(IncidenceMatrix& mac)
{
	int** macierz = mac.zwrocMacierz();
	int E = mac.liczbaKrawedzi();
	int V = mac.liczbaWierzcholkow();

	// wstepna inicjalizacja wektorow
	for (int i = 0; i < V; i++)
	{
		list<int> row;
		_V.push_back(row);
	}

	for (int i = 0; i<V; i++) {
		for (int j = 0; j<E; j++) {
			if (macierz[i][j] == 1) {
				for (int k = 0; k<V; k++) {
					if (k != i && macierz[k][j] == 1) {
						_V[i].push_back(k);
						break;
					}
				}
			}
		}
	}

}

void AdjacencyList::wypiszListe() const
{
	cout << endl << "Lista Sasiedztwa" << endl;
	for (unsigned i = 0; i<_V.size(); i++) {
		cout << i << ": ";
		for (list<int>::const_iterator iter = _V[i].begin(); iter != _V[i].end(); iter++) {
			cout << *iter << " -> ";
		}
		cout << endl;
	}
}

// cos zle dziala
void AdjacencyList::wczytajDane()
{
	cout << endl << "Wczytywanie listy sasiedztwa" << endl;
	cout << "Podaj liczbe krawedzi V: ";
	int size;
	cin >> size;

	for (int i = 0; i < size; i++)
	{
		list<int> row;
		_V.push_back(row);
	}

	for (int i = 0; i<size; i++)
	{
		cout << "Podaj sasiedztwo wierzcholka " << i << ":  (zakoncz x)" << endl;
		string a;
		cin >> a;
		while (a != "x")
		{
			int c = atoi(a.c_str());
			if (c >= size || c < 0)
			{
				cout << "Blad, za duzy lub za maly wierzcholek!" << endl;
				i--;
				a = "x";
				continue;
			}
			if (i == c)
			{
				cin >> a;
				continue;
			}

			// dwa aby bylo symetrycznie (grafy proste)
			_V[i].push_back(c);
			_V[c].push_back(i);
			cin >> a;
		}

	}

	// aby nie bylo powtorzen
	for (int i = 0; i < size; i++)
	{
		_V[i].sort();
		_V[i].unique();
	}

}
