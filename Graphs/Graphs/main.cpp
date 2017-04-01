#include <iostream> 
#include "AdjacencyMatrix.h"
#include "IncidenceMatrix.h"
#include "AdjacencyList.h"

#include <string>

int main()
{
	using namespace std;

	string stra = "011\n100\n100\n";

	AdjacencyMatrix adja(stra);
	cout << adja.getString();

	IncidenceMatrix inc(adja);
	cout << inc.getString();

	AdjacencyList list(inc);
	cout << list.getString();

	const char* fileName = "a.txt";
	AdjacencyMatrix adja2(fileName);
	cout << adja2.getString();


	system("pause");
}

