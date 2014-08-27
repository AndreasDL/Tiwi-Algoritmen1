#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
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
	int max = 0;
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++){
		if (*it > max){
			max = *it;
		}
	}
	max++;
	
	int* array = new int[max];
	
	for (int i = 0; i < max; i++){
		array[i] = 0;
	}
	
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++){
		array[*it]++;
	}
	
	int waarde = 0;
	int count = array[0];
	for (int i = 0; i < max; i++){
		if ( array[i] > count){
			count = array[i];
			waarde = i;
		}
	}
	delete[] array;
	return waarde;
	
}

int sortMode(vector<int> &v){
	sort(v.begin(), v.end());
	int modus = v[0];
	int moduscnt = 1;
	int huidig = v[0];
	int huidigcnt = 1;
	for (int i = 1; i < v.size() ; i++){
		if (v[i] == huidig){
			huidigcnt++;
		}
		else{
			if (huidigcnt > moduscnt){
				moduscnt = huidigcnt;
				modus = huidig;
			}
			huidig = v[i];
			huidigcnt = 1;
		}		
	}
	return modus;
}


int main(){
	srand(time(0));
	
	
	cout << "Size\t\tTijd map\tTijd array\tTijd sort\tOpm" << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	
	for (int size = 5000; size < 10000000; size *= 2){
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
		
		Chrono c3;
		c3.start();
		int mode_sort = sortMode(v);
		c3.stop();
		
		cout << size <<  "\t\t" << c.tijd() << "\t\t" << c2.tijd() << "\t\t" << c3.tijd() << "\t";
		cout << mode_map << " : " << mode_array << " : " << mode_sort;
	
		cout << endl;
	}
	cout << "-----------------------------------------------------------------------------" << endl;
	cin.get();
	return 0;
}
