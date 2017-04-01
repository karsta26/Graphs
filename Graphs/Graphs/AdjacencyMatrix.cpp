#include "AdjacencyMatrix.h"


#include "AdjacencyList.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

AdjacencyMatrix::AdjacencyMatrix() : _V(0), _E(0), _matrix(NULL)
{}

AdjacencyMatrix::AdjacencyMatrix(int ** matrixOrigin, int sizeOfMatrix)
{
	_V = sizeOfMatrix;
	setMemory(_V, _V);
	for (int i = 0; i < _V; ++i)
		for (int j = 0; j < _V; ++j)
			_matrix[i][j] = matrixOrigin[i][j];

	countEdges();
}

// dziala tylko gdy wczystko jest ok w pliku
AdjacencyMatrix::AdjacencyMatrix(const char* fileName)
{
	ifstream file;
	file.open(fileName);
	if (file)
	{
		// liczy liczbe kolumn
		string buf;
		int numOfColumns;
		getline(file, buf);
		numOfColumns = buf.size()/2 + 1;
		file.seekg(0);

		// liczy liczbe wierszy
		int tmpNumber = 0;
		string tmpString;
		while (1)
		{
			if (file.eof())
				break;
			getline(file, tmpString);
			tmpNumber++;
		}

		file.seekg(0);

		int numOfRows =  tmpNumber;
		if (numOfColumns != numOfRows)
		{
			cout << "Blad czytania z pliku: liczba wierszy jest rozna od liczby kolumn" << endl;
			file.close();
			setMemory(1, 1);
		}
		else
		{
			_V = numOfRows;

			setMemory(numOfRows, numOfColumns);

			for (int i = 0; i < numOfRows; ++i)
				for (int j = 0; j < numOfColumns; ++j)
					file >> _matrix[i][j];

			countEdges();
			file.close();
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

AdjacencyMatrix::AdjacencyMatrix(const string strMatrix)
{
	string myDelim("\n");
	int positionOfNewLine = strMatrix.find_first_of(myDelim);
	_V =  positionOfNewLine;

	stringstream stringHelper(strMatrix);

	setMemory(_V, _V);

	for (int i = 0; i < _V; ++i)
		for (int j = 0; j < _V; ++j)
		{
			char tmpChar;
			stringHelper >> tmpChar;
			if (tmpChar == '\\n')
				stringHelper >> tmpChar;
			_matrix[i][j] = int(tmpChar) -48;
		}
	countEdges();
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

void AdjacencyMatrix::setMemory(const int x, const int y)
{
	_matrix = new int*[x];
	for (int i = 0; i < y; ++i)
		_matrix[i] = new int[y];

	for (int i = 0; i < x; ++i)
		for (int j = 0; j < y; ++j)
			_matrix[i][j] = 0;
}

void AdjacencyMatrix::countEdges()
{
	int sum = 0;
	for (int i = 0; i < _V; ++i)
		for (int j = 0; j < _V; ++j)
			sum += _matrix[i][j];
	_E = sum / 2;
}

string AdjacencyMatrix::getString() const
{
	stringstream toGive("");
	if (_matrix)
	{
		toGive << endl << "Adjacency Matrix" << endl;
		toGive << " ";
		for (int i = 0; i < _V; ++i)
		{
			toGive << "  " << i;
		}
		toGive << endl << string(_V * 3 + 1, '-') << endl;
		for (int i = 0; i < _V; ++i)
		{
			toGive << i << "/ ";
			for (int j = 0; j < _V; ++j)
				toGive << _matrix[i][j] << "  ";
			toGive << endl;
		}
	}
	return toGive.str();
}

AdjacencyMatrix::AdjacencyMatrix(AdjacencyList* Adjacencylist)
{
	vector< list<int> > myList = Adjacencylist->getList();
	_V = myList.size();
	setMemory(_V, _V);
	for (unsigned i = 0; i<myList.size(); ++i) {
		for (list<int>::const_iterator iter = myList[i].begin(); iter != myList[i].end(); ++iter) {
			_matrix[i][*iter] = 1;
		}
	}
	countEdges();
}
