#include <iostream> 
#include "AdjacencyMatrix.h"
#include "IncidenceMatrix.h"
#include "AdjacencyList.h"

#include <string>
#include <sstream>
#include <numeric>
#include <algorithm>

bool isGraphString(std::string vertexList);
AdjacencyList constructGraph(std::string vertexList);

int main()
{
	using namespace std;
	/*
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
	*/

	AdjacencyList myList = constructGraph("1 1 2 3 3 4 4 6 8 4 2 1 2 1");
	cout << myList.getString();
	

	system("pause");
}

bool isGraphString(std::string vertexList)
{
	using namespace std;
	// przepisuje wszystkie dane ze stringa do vectora
	stringstream helperString(vertexList);
	vector<int> vertexTab;
	int intHelper;
	for(unsigned i=0;i<vertexList.size()/2+1;++i)
	{
		helperString >> intHelper;
		vertexTab.push_back(intHelper);
	}
	// sumuje wszystkie elementy
	int sumOfElements = accumulate(vertexTab.begin(), vertexTab.end(), 0);
	
	// jesli suma jest nieparzysta to nie jest graficzny
	if (sumOfElements % 2 == 1)
		return false;

	// sortowanie od najwiekszego
	sort(vertexTab.begin(), vertexTab.end());
	reverse(vertexTab.begin(), vertexTab.end());

	// jestli nie ma na tyle odpowiadajacych wierzcholkow to nie jest graficzny
	if (vertexTab[0] >= vertexTab.size())
		return false;

	unsigned originSize = vertexTab.size();
	// glowna petla
	for (unsigned i = 0; i< originSize; ++i)
	{
		// jesli ktorykolwiek wierzcholek jest ujemny, to nie jest graficzny
		for (unsigned k = 0; k< vertexTab.size(); ++k){
			if (vertexTab[k] < 0)
				return false;
		}
		// pobiera poczatek = wierzcholek o najwiekszym stopniu
		unsigned bigOne = vertexTab.front();
		// jest posortowane wiec jesli nie byl ujemny a jest rowny 0 to znaczy ze jest graficzny
		if (bigOne == 0)
			return true;
		// jestli nie ma na tyle odpowiadajacych wierzcholkow to nie jest graficzny
		if (bigOne >= vertexTab.size())
			return false;
		// usuwa najwiekszy element = poczatek
		vertexTab.erase(vertexTab.begin());
		// odejmuje 1 od kolejnych wierzcholkow 
		for (unsigned j = 0; j< bigOne; ++j)
			vertexTab[j] -= 1;

		// sortuje ponownie
		sort(vertexTab.begin(), vertexTab.end());
		reverse(vertexTab.begin(), vertexTab.end());
	}
	// gdy ilosc wierzcholkow = 0
	return false;
}

AdjacencyList constructGraph(std::string vertexList)
{
	using namespace std;
	// czy da sie taki skonstruowac
	if (!isGraphString(vertexList))
		return false;

	// przepisuje wszystko do vectora
	stringstream helperString(vertexList);
	vector<int> vertexTab;
	int intHelper;
	for (unsigned i = 0; i< vertexList.size() / 2 + 1; ++i)
	{
		helperString >> intHelper;
		vertexTab.push_back(intHelper);
	}

	// inicjalizacja listy
	AdjacencyList myList(vertexTab.size());

	// sortowanie od najwiekszego
	sort(vertexTab.begin(), vertexTab.end());
	reverse(vertexTab.begin(), vertexTab.end());
	
	// glowna petla
	for (unsigned i = 0; i < vertexTab.size() - 1; ++i)
	{
		// pobiera element obecnie rozpatrywany
		int size = vertexTab[i];
		// jesli jego stopien == 0 to sprawdza czy dalej tez sa zera, idzie do konca 
		// jesli jest jakis niezerowy to sie ustawia na niego
		while (size == 0 && i < vertexTab.size() - 1){
			i++;
			size = vertexTab[i];
		}
		// nastepny wierzcholek po nie zerowym 
		int next = i + 1;

		// dopoki rozny od zera to rozdawaj innym wierzcholkom polaczenia z obecnym
		while(size != 0)
		{
			// kiedy nastepny jest == 0 to nie moze mu dac polaczenia
			// sprawdza czy nastepne tez sa rowne 0
			while (vertexTab[next] == 0 && next < vertexTab.size())
				next++;
			// dodaje wlasciwa krawedz do listy sasiedztwa
			myList.addEdge(i, next);
			// zmniejsza stopien obecnego wierzcholka
			size--;
			// zmiejsza stopien nastepnego wierzcholka 
			vertexTab[next] -= 1;
			// idzie dalej z rozdawaniem polaczen do siebie
			next++;
		}
		
	}

	return myList;
}

