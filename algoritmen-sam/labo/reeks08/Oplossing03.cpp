#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>
#include <cmath>
#include "chrono.h"

using namespace std;



// Zelfde als oplossing 2 maar nu met pointers naar vectoren i.p.v. vectoren



// De grootte van de tabel
const int m = 1000;

// De tabel zelf: m groot, bevat dus m vectoren met woorden die 
// op een zelfde index mappen.
vector<vector<string>* > anagrammen (m);

// Karakter -> waarde (priemgetal)
map<char,int> karakterWaarden;


bool isPriem(int i){
	int j = 2;
	int stop = sqrt(i); // een getal groter dan de vierkantswortel kan geen deler zijn
	while (j <= stop && i % j != 0){
		j++;
	}
	return j > stop;
}

// Opvullen map karakterwaarden
void bereken_karakterWaarden(){
	int i = 1;
	for (char c = 'a'; c <= 'z'; c++){
		while (!isPriem(i)){
			i++;
		}
		karakterWaarden[c] = i;
		i++;
	}
}

// Voor een zeker woord, bepaal de index
// Alle anagrammen zullen de zelfde index hebben. Niet alle woorden
// met een zelfde index zijn noodzakelijk anagrammen.
int bereken_index(string woord){
	unsigned int resultaat = 1; // Unsigned int want een index moet >= 0 zijn
	// Karakters in woord overlopen en resultaat vermenigvuldigen met de
	// waarde van dat karakter.
	for (string::iterator it = woord.begin(); it != woord.end(); it++){
		resultaat *= karakterWaarden[*it];
	}
	// Het resultaat mag niet groter dan (m-1) zijn -> modulo
	return resultaat%m;	
}

void vul_anagrammen_op(){
	ifstream in("woordenlijst.txt");
	if (!in.is_open()){
		cout << "Fout bij openen woordenlijst" << endl;	
	}
	string woord;
	int index;
	while (!in.fail()){
		in >> woord;
		index = bereken_index(woord);
		if (anagrammen[index] == 0){
			anagrammen[index] = new vector<string>();
		}
		anagrammen[index] -> push_back(woord);
	}
	in.close();	
}

bool isAnagramVan(string woord1, string woord2){
	bool result;
	if (woord1.length() != woord2.length()){
		result = false;
	}
	else{
		sort(woord1.begin(), woord1.end());
		sort(woord2.begin(), woord2.end());
		result = (woord1 == woord2);
	}
	return result;
}

void zoek_anagrammen(){
	ifstream in("bepaal_anagrammen_van.txt");
	if (!in.is_open()){
		cout << "Fout bij openen lijst te zoeken anagrammen" << endl;	
	}
	string woord;
	int index;
	while (!in.fail()){
		in >> woord;
		index = bereken_index(woord);
		cout << woord << endl;
		for (vector<string>::iterator it = anagrammen[index] -> begin();
			it != anagrammen[index] -> end(); it++){
				if (isAnagramVan(woord, *it)){
					cout << "\t" << *it << endl;
				}
		}
	}
	in.close();		
}

void toonStatistieken(){
	int legePlaatsen = 0;
	for (int i = 0; i < m; i++){
		if (anagrammen[i]  == 0){ // nullpointer
			legePlaatsen++;
		}
	}
	cout << m << " plaatsen in tabel" << endl;
	cout << legePlaatsen << " nog vrije plaatsen in tabel" << endl;
}

int main(){
	Chrono c;
	c.start();
	bereken_karakterWaarden();
	cout << "woordenlijst inlezen" << endl;
	vul_anagrammen_op();
	cout << "anagrammen zoeken" << endl;
	zoek_anagrammen();
	c.stop();
	cout << "Benodigde tijd: " << c.tijd() << endl;
	toonStatistieken();
	for (int i = 0; i < m; i++){
		delete anagrammen[i];
	}
	cout << ">>> ";
	cin.get();
	return 0;	
}
