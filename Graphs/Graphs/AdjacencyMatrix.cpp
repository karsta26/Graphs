#include "AdjacencyMatrix.h"


#include "AdjacencyList.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

AdjacencyMatrix::AdjacencyMatrix() : _V(0), _E(0), _matrix(NULL)
{}

// dziala tylko gdy wczystko jest ok w pliku
AdjacencyMatrix::AdjacencyMatrix(const char* nazwaPliku)
{
	ifstream plik;
	plik.open(nazwaPliku);
	if (plik)
	{
		// liczy liczbe kolumn
		string buf;
		int liczbaKolumn;
		getline(plik, buf);
		liczbaKolumn = buf.size() / 2+1;
		plik.seekg(0);

		// liczy liczbe wierszy
		int ile = 0;
		string asd;
		while (1)
		{
			if (plik.eof())
				break;
			getline(plik, asd);
			ile++;
		}

		plik.seekg(0);

		int liczbaWierszy = ile;
		if (liczbaKolumn != liczbaWierszy)
		{
			cout << "Blad czytania z pliku: liczba wierszy jest rozna od liczby kolumn" << endl;
			plik.close();
			zarezerwujPamiec(liczbaWierszy, liczbaWierszy);
		}
		else
		{
			_V = liczbaWierszy;

			zarezerwujPamiec(liczbaWierszy, liczbaKolumn);

			for (int i = 0; i < liczbaWierszy; i++)
				for (int j = 0; j < liczbaKolumn; j++)
					plik >> _matrix[i][j];

			policzKrawedzie();
			plik.close();
		}
	}
	else
	{
		cout << "Blad otwarcia pliku" << endl;
		_E = 0;
		_V = 0;
		_matrix = NULL;
	}
}


AdjacencyMatrix::~AdjacencyMatrix()
{
	if (_matrix)
	{
		for (int i = 0; i < _V; ++i)
			delete[] _matrix[i];
		delete[] _matrix;
	}
}

void AdjacencyMatrix::wypiszMacierz() const
{
	if (_matrix)
	{
		cout << endl << "Macierz sasiedztwa" << endl;
		cout << " ";
		for (int i = 0; i < _V; ++i)
		{
			cout << "  " << i;
		}
		cout << endl << string(_V * 3 + 1, '-') << endl;
		for (int i = 0; i < _V; ++i)
		{
			cout << i << "/ ";
			for (int j = 0; j < _V; ++j)
				cout << _matrix[i][j] << "  ";
			cout << endl;
		}
	}

}

void AdjacencyMatrix::wczytajDane()
{
	cout << endl << "Wczytywanie macierzy sasiedztwa" << endl;
	cout << "Podaj liczbe wierzcholkow V: ";
	cin >> _V;
	zarezerwujPamiec(_V, _V);
	cout << endl << "Podaj co z czym sasiaduje np. 1 2, czyli wierzcholek 1 sasiaduje z wierzcholkiem 2" << endl;
	cout << "Zakoncz piszac  0 0" << endl;
	int x, y;
	cin >> x >> y;
	while (x != 0 || y != 0)
	{
		if (x >= _V || y >= _V || x< 0 || y<0)
		{
			cout << "Blad danych! Tylko wartosci mniejsze od liczby krawedzi!" << endl;
		}
		else
		{
			if (_matrix[x][y] == 1)
				cout << "Taka krawedz juz istnieje!" << endl;
			else if (x == y)
			{
				cout << "To ma byc graf prosty!" << endl;
			}
			else
			{
				_matrix[x][y] = 1;
				_matrix[y][x] = 1;
			}
		}

		cin >> x >> y;
	}
	policzKrawedzie();

}

void AdjacencyMatrix::zarezerwujPamiec(const int x, const int y)
{
	_matrix = new int*[x];
	for (int i = 0; i < y; ++i)
		_matrix[i] = new int[y];

	for (int i = 0; i < x; ++i)
		for (int j = 0; j < y; ++j)
			_matrix[i][j] = 0;
}

void AdjacencyMatrix::policzKrawedzie()
{
	int sum = 0;
	for (int i = 0; i < _V; ++i)
		for (int j = 0; j < _V; ++j)
			sum += _matrix[i][j];
	_E = sum / 2;
}

AdjacencyMatrix::AdjacencyMatrix(AdjacencyList* listaSasiedztwa)
{
	std::vector< std::list<int> > lista = listaSasiedztwa->zwrocListe();
	_V = lista.size();
	zarezerwujPamiec(_V, _V);
	for (unsigned i = 0; i<lista.size(); i++) {
		for (list<int>::const_iterator iter = lista[i].begin(); iter != lista[i].end(); iter++) {
			_matrix[i][*iter] = 1;
		}
	}
	policzKrawedzie();
}
