#include "AdjacencyList.h"

#include <iostream>
#include <sstream>

using namespace std;

AdjacencyList::AdjacencyList()
{}

AdjacencyList::AdjacencyList(IncidenceMatrix& incMatrix)
{
	int** incMatrixValue = incMatrix.getMatrix();
	int E = incMatrix.getE();
	int V = incMatrix.getV();

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
