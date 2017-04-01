#include <iostream> 
#include "AdjacencyMatrix.h"
#include "IncidenceMatrix.h"
#include "AdjacencyList.h"

#include <string>

int main()
{
	using namespace std;

	string stra = "111\n100\n100\n";
	AdjacencyMatrix adja(stra);
	cout << adja.getString();


	system("pause");
}

