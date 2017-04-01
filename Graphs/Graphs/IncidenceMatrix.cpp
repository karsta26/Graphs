#include "IncidenceMatrix.h"

#include <iostream>
#include <string>
#include <sstream>
using namespace std;


IncidenceMatrix::IncidenceMatrix() : _V(0), _E(0), _matrix(NULL)
{}

IncidenceMatrix::IncidenceMatrix(AdjacencyMatrix& adjMatrix)
{
	_V = adjMatrix.getV();
	_E = adjMatrix.getE();
	setMemory(_V, _E);
	int edgeNumber = 0;
	int** adjMatrixValue = adjMatrix.getMatrix();
	for (int i = 0; i<_V - 1; ++i) {
		for (int j = i + 1; j<_V; ++j) {
			if (adjMatrixValue[i][j] == 1) {
				_matrix[i][edgeNumber] = 1;
				_matrix[j][edgeNumber] = 1;
				edgeNumber++;
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
	toGive << endl << "Incidence Matrix" << endl;
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
