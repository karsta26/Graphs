#include <iostream> 
#include "AdjacencyMatrix.h"
#include "IncidenceMatrix.h"
#include "AdjacencyList.h"

int main()
{
	using namespace std;
	const char* nazwa = "a.txt";
	AdjacencyMatrix tab(nazwa);
	// MacierzSasiedztwa tab;
	// tab.wczytajDane();
	tab.wypiszMacierz();
	IncidenceMatrix tab2(tab);
	tab2.wypiszMacierz();
	cout << endl << "Krawedzie: " << tab2.liczbaKrawedzi() << " Wierzcholki: " << tab2.liczbaWierzcholkow() << endl;
	cout << endl;

	AdjacencyList li(tab2);
	li.wypiszListe();

	AdjacencyMatrix aa(&li);
	aa.wypiszMacierz();

	AdjacencyList k;
	k.wczytajDane();
	k.wypiszListe();

	AdjacencyMatrix al(&k);
	al.wypiszMacierz();

	IncidenceMatrix ll(al);
	ll.wypiszMacierz();

	system("pause");

}

