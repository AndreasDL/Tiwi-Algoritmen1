#include <iostream>
#include <vector>
#include <cstdlib>
#include "SorteerMethode.cpp"

// Insertion sort is een eenvoudige sorteermethode
// Het correct te plaatsen element wordt in een hulpvariabele
// opgeslagen en de tabel wordt afgelopen tot de correcte 
// plaats gevonden wordt.

using namespace std;
template <typename T>
class InsertionSort: public SorteerMethode<T>{
	public:
		void operator()(vector<T> &v);
		string getName();
};

template <typename T>
string InsertionSort<T>::getName(){
	return "Insertion sort";
}

template <typename T>
void InsertionSort<T>::operator() (vector<T> &v){
	for (unsigned int i = 1; i < v.size(); i++){
		// De eerste i elementen zijn reeds gesorteerd
		// h is de waarde die we moeten goedzetten
		T h = v[i];
		int j = i - 1;
		// We overlopen het reeds gesorteerde stuk tot we de plek
		// vinden waar h moet staan.
		// Opgelet: werken met h, op v[i] kan er al een andere waarde 
		// staan.
		while (j >= 0 && v[j] > h){
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = h;
	}
}

