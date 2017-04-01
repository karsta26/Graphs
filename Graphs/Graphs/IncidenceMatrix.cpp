#include "IncidenceMatrix.h"

#include <iostream>
#include <string>
#include <sstream>
using namespace std;


IncidenceMatrix::IncidenceMatrix() : _V(0), _E(0), _matrix(NULL)
{}

IncidenceMatrix::IncidenceMatrix(AdjacencyMatrix& sas)
{
	_V = sas.getV();
	_E = sas.getE();
	setMemory(_V, _E);
	int krawedz = 0;
	int** macSas = sas.getMatrix();
	for (int i = 0; i<_V - 1; i++) {
		for (int j = i + 1; j<_V; j++) {
			if (macSas[i][j] == 1)
			{
				_matrix[i][krawedz] = 1;
				_matrix[j][krawedz] = 1;
				krawedz++;
			}
		}
	}
}


IncidenceMatrix::~IncidenceMatrix()
{
	if (_matrix)
	{
		for (int i = 0; i < _V; ++i)
			delete[] _matrix[i];
		delete[] _matrix;
	}
}

void IncidenceMatrix::wypiszMacierz() const
{
	cout << endl << "Macierz incydencji" << endl;
	cout << " ";
	for (int i = 0; i < _E; ++i)
	{
		cout << "  " << i;
	}
	cout << endl << string(_E * 3 + 1, '-') << endl;
	for (int i = 0; i < _V; ++i)
	{
		cout << i << "/ ";
		for (int j = 0; j < _E; ++j)
			cout << _matrix[i][j] << "  ";
		cout << endl;
	}
}

void IncidenceMatrix::setMemory(const int x, const int y)
{
	_matrix = new int*[x];
	for (int i = 0; i < x; ++i)
		_matrix[i] = new int[y];

	for (int i = 0; i < x; ++i)
		for (int j = 0; j < y; ++j)
			_matrix[i][j] = 0;
}

std::string IncidenceMatrix::getString() const
{
	stringstream toGive("");
	toGive << endl << "Macierz incydencji" << endl;
	toGive << " ";
	for (int i = 0; i < _E; ++i)
	{
		toGive << "  " << i;
	}
	toGive << endl << string(_E * 3 + 1, '-') << endl;
	for (int i = 0; i < _V; ++i)
	{
		toGive << i << "/ ";
		for (int j = 0; j < _E; ++j)
			toGive << _matrix[i][j] << "  ";
		toGive << endl;
	}
	return toGive.str();
}
