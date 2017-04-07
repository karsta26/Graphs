#include "AdjacencyList.h"

#include <iostream>
#include <sstream>

using namespace std;

AdjacencyList::AdjacencyList(const int numOfVertex)
{
	// wstepna inicjalizacja wektorow
	for (int i = 0; i < numOfVertex; i++) {
		list<int> row;
		_list.push_back(row);
	}
	_E = 0;
	_V = numOfVertex;
}

AdjacencyList::AdjacencyList(IncidenceMatrix& incMatrix)
{
	int** incMatrixValue = incMatrix.getMatrix();
	int E = incMatrix.getE();
	int V = incMatrix.getV();
	_E = E;
	_V = V;

	// wstepna inicjalizacja wektorow
	for (int i = 0; i < V; i++) {
		list<int> row;
		_list.push_back(row);
	}

	for (int i = 0; i<V; i++) {
		for (int j = 0; j<E; j++) {
			if (incMatrixValue[i][j] == 1) {
				for (int k = 0; k<V; k++) {
					if (k != i && incMatrixValue[k][j] == 1) {
						_list[i].push_back(k);
						break;
					}
				}
			}
		}
	}

}

std::string AdjacencyList::getString() const
{
	stringstream toGive("");
	toGive << endl << "Adjacency List" << endl;
	for (unsigned i = 0; i<_list.size(); i++) {
		toGive << i << ": ";
		for (list<int>::const_iterator iter = _list[i].begin(); iter != _list[i].end(); iter++) {
			toGive << *iter << " -> ";
		}
		toGive << endl;
	}

	return toGive.str();
}

bool AdjacencyList::addEdge(const int vertexOne, const int vertexTwo)
{
	if (vertexOne >= _V || vertexTwo >= _V)
		return false;
	if (vertexOne == vertexTwo)
		return false;
	for (list<int>::const_iterator iter = _list[vertexOne].begin(); iter != _list[vertexOne].end(); iter++) 
	{
		if(*iter == vertexTwo)
			return false;
	}
	_list[vertexOne].push_back(vertexTwo);
	_list[vertexTwo].push_back(vertexOne);
	return true;
}
