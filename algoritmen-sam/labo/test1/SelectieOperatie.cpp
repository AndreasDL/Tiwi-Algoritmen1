#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iomanip>

#include "chrono.h"

using namespace std;

template<typename T>
T k_heel_klein(vector<T> &v, int k,  int start, int stop){
	// We kunnen gewoon k keer het kleinste zoeken
	// = k eerste stappen selection sort uitvoeren.
	// voor k = 5 wordt de tabel na deze methode:
	// 2 2 4 5 7 9 9 9 9 8 // enkel de eerste 5 staan gesorteerd
	
	for (int i = 0; i < k; i++){
		// k keer het kleinste zoeken
		int pos = i; // positie kleinste
		for (int j = i; j <= stop; j++){
			if (v[j] < v[pos]){
				pos = j;
			}
		}
		// plaats het kleinste vooraan
		swap(v[pos],v[i]);
	}
	// nu hebben we een deel van de tabel gesorteerd 
	// (de eerste k elementen)
	return v[k-1];
}

template <typename T>
void daalAf(vector<T> &v, int start, int stop){
	// laat het element v[start] afdalen in de heap
	// ga niet voorbij stop
	int i = start;
	int toSwap = i;
	int l = 2*i+1;
	int r = 2*i+2;
	
	if (l <= stop && v[l] < v[toSwap]){
		toSwap = l;
	}
	if (r <= stop && v[r] < v[toSwap]){
		toSwap = r;
	}
	while (toSwap != i){
		swap(v[i],v[toSwap]);
		i = toSwap;
		l = 2*i+1;
	    r = 2*i+2;
		
		if (l <= stop && v[l] < v[toSwap]){
			toSwap = l;
		}
		if (r <= stop && v[r] < v[toSwap]){
			toSwap = r;
		}		
	}	
}

template<typename T>
T k_een_beetje_groter(vector<T> &v, int k, int start, int stop){
	// We bouwen een dalende heap op en voeren de k eerste stappen
	// van heapsort uit.

	// Bouw minheap op
	for (int i = (stop-start-2)/2; i >= 0; i--){
		daalAf(v,i,stop);
	}
	//print(v);
	// Het kleinste element staat in de wortel
	for (int i = 0; i < k-1; i++){
		// k-1keer de wortel nemen en die achteraan plaatsen
		swap(v[0],v[stop-i]);
		// heap herstellen
		daalAf(v,start,stop-i-1); // stop-i-1 want stop-i mag niet meedoen
	}
	// het k de kleinste element staat nu in de wortel.
	return v[0];
}

template<typename T>
void daalAfMaxHeap(vector<T> &v, int start, int stop){
	int i = start;
	int toSwap = i;
	int l = 2*i+1;
	int r = 2*i+2;
	
	if (l <= stop && v[l] > v[toSwap]){
		toSwap = l;
	}
	if (r <= stop && v[r] > v[toSwap]){
		toSwap = r;
	}
	// Zolang het element niet op zijn plaats staat.
	while (toSwap != i){
		swap(v[toSwap],v[i]);
		i = toSwap;
		l = 2*i+1;
		r = 2*i+2;
		
		if (l <= stop && v[l] > v[toSwap]){
			toSwap = l;
		}
		if (r <= stop && v[r] > v[toSwap]){
			toSwap = r;
		}
	}
}

template<typename T>
T k_een_beetje_groter_maar_nu_anders(vector<T> &v, int k, int start, int stop){
	// Als we zoeken naar het kde kleinste element, dan zoeken we naar de
	// grootste waarde van de k kleinste elementen
	// We houden een heap bij met k waarden (de k kleinste waarden)
	// We inititaliseren deze met de eerste k waarden
	
	for (int i = k/2; i >= 0; i--){
		daalAfMaxHeap(v,i,k-1);
	}
	
	// nu moeten we de rest van de elementen overlopen
	for (int i = k; i <= stop; i++){
		// als het nieuwe element kleiner is dan de wortel van de heap
		// dan moet het hier in staan.
		if (v[i] < v[0]){
			swap(v[i],v[0]);
			// herstel de heap
			daalAfMaxHeap(v,0,k-1);
		}
	}
	// De heap bevat nu de k kleinste getallen, de wortel van de heap
	// bevat het grootste getal van de k kleinste getallen -> de k-de
	// kleinste waarde.
	//print(v);
	return v[0];
	
}

template<typename T>
T nog_grotere_k(vector<T> &v, int k, int start, int stop){
	// pivot kiezen
	int index = start;
	T pivot = v[index];
	// plaats pivot achteraan zodat we hem weten staan
	swap(v[index],v[stop]);
	
	
	// lopers
	int i = start;
	int j = stop-1; // op v[stop] staat de pivot, laat deze met rust
	
	while (i <= j){
		while (i < stop && v[i] < pivot){
			i++;
		}
		while (j >= start && v[j] > pivot){
			j--;
		}
		if (i <= j){
			swap(v[i],v[j]);
			i++;
			j--;
		}		
	}
	
	// pivot op zijn definitieve plaats zetten
	swap(v[i],v[stop]);
	
	if ( i == k-1){
		return v[i];
	}
	else if (i > k-1){
		return nog_grotere_k(v,k,start,i);
	}
	else{
		return nog_grotere_k(v,k-i,i+1,stop);
	}
}

template<typename T>
void print(vector<T> &v){
	for (unsigned int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(){
	int n = 10000;

	srand(time(0));
	
	vector<int> v;	
	for (int i = 0; i < n; i++){
		v.push_back(rand());
	}	
	
	Chrono c;
	int res[4];
	
	for (int index = 1; index < n/2; index+=n/100){	
		cout << setw(10) << index;
		
		c.start();
		res[0] = k_heel_klein(v,index,0,v.size()-1);
		c.stop();
		cout << setw(15) << c.tijd();
		
		c.start();
		res[1] = k_een_beetje_groter(v,index,0,v.size()-1);
		c.stop();
		cout << setw(15) << c.tijd();
		
		c.start();
		res[2] = k_een_beetje_groter_maar_nu_anders(v,index,0,v.size()-1);
		c.stop();
		cout << setw(15) << c.tijd();
		
		c.start();
		res[3] = nog_grotere_k(v,index,0,v.size()-1);
		c.stop();
		cout << setw(15) << c.tijd();
		
		
		for (int i = 1; i < 4; i++){
			if (res[i] != res[i-1]){
				cout << "fout" << endl;
				return 1;
			}
		}
		cout << endl;
	}
}
