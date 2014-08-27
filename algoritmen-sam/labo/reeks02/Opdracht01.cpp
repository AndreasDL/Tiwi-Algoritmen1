#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include "chrono.h"

using namespace std;

int modeMap(const vector<int> &v){
	// frequentiemap
	map<int,int> frequentie;
		
	// tellen
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++){
		frequentie[*it]++;
	}
	
	// grootste zoeken
	int waarde = frequentie.begin() -> first;
	int count = frequentie.begin() -> second;
	for (map<int,int>::iterator it = frequentie.begin(); it != frequentie.end(); it++){
		if ( it -> second > count){
			count = it -> second;
			waarde = it -> first;
		}
	}
	
	return waarde;
}

int modeArray(const vector<int> &v){
	int* array = new int[v.size()];
	
	for (int i = 0; i < v.size(); i++){
		array[i] = 0;
	}
	
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++){
		array[*it]++;
	}
	
	int waarde = 0;
	int count = array[0];
	for (int i = 0; i < v.size(); i++){
		if ( array[i] > count){
			count = array[i];
			waarde = i;
		}
	}
	delete[] array;
	return waarde;
	
}



int main(){
	srand(time(0));
	
	
	cout << "Size\tTijd map\tTijd array\tOpm" << endl;
	cout << "------------------" << endl;
	
	for (int size = 500; size < 50000; size *= 2){
		vector<int> v;		
		for (int i = 0; i < size; i++){
			v.push_back(rand());
		}
		Chrono c;
		c.start();
		int mode_map = modeMap(v);
		c.stop();
	
		
		Chrono c2;
		c2.start();
		int mode_array = modeArray(v);
		c2.stop();
		
		
		cout << size <<  "\t" << c.tijd() << "\t" << c2.tijd() << "\t";
		if (mode_array != mode_map){
			cout << "Verschillende modus !!!!!";	
		}
		cout << endl;
	}
	cout << "------------------" << endl;
	cin.get();
	return 0;
}
