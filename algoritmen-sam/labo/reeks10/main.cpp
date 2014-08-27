#include <iostream>
#include <fstream>
#include <iomanip>
#include "graaf.h"

using namespace std;

int min(int a, int b){
	return (a < b ? a : b);
}

int main(){
	
	ifstream in;
	in.open("graaf.txt");
	
	Graaf<ONGERICHT> graaf;
	
	try{
		graaf.lees(in);
		graaf.schrijf(cout);
	}
	catch (GraafExceptie ex){
		cout << ex << endl;	
	}
	
	
	// Tabel aanmaken van grootte n, voorlopig zit elke knoop in een afzonderlijk
	// segment met maar één knoop;
	int n = graaf.aantal_knopen();
	int* segmenten = new int[n];
	for (int i = 0; i < n; i++){
		segmenten[i] = i;
	}
	
	// Nu overlopen we alle verbindingen, is er een verbinding tussen twee knopen
	// dan voegen we de segmenten samen.
	for (int i = 0; i < n; i++){
		for (map<int, int>::const_iterator it = graaf[i].begin(); 
			it != graaf[i].end(); it++){
					int segment = min(segmenten[it -> first], segmenten[i]);
					segmenten[i] = segment;
					segmenten[it -> first] = segment;
					cout << "knoop " << i << " en knoop " << it -> first << " horen bij segment " << segment << endl;
			}
	}
		
	// Uitschrijven lijst segmenten
	cout << endl << endl << "knoop:   ";
	for (int i = 0; i < n; i++){
		cout << setw(3) << i << " ";
	}
	cout << endl << "segment: ";
	for (int i = 0; i < n; i++){
		cout << setw(3) << segmenten[i] << " ";
	}
	cout << endl;
	
	
	delete[] segmenten;
	cout << ">>> ";
	cin.get();
	
	
	
	return 0;
}
