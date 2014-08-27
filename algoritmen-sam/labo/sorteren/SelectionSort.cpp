#include <iostream>
#include <vector>
#include <cstdlib>
#include "SorteerMethode.cpp"

using namespace std;
template <typename T>
class SelectionSort: public SorteerMethode<T>{
	public:
		void operator()(vector<T> &v);
		string getName();
};

template <typename T>
string SelectionSort<T>::getName(){
	return "Selection sort";
}

template <typename T>
void SelectionSort<T>::operator() (vector<T> &v){
	for (unsigned int i = v.size() -1; i > 0 ; i--){
		// Zoek het grootste element uit de tabel en plaats dit achteraan
		// Zoek het grootste element uit de tabel zonder de laatste waarde
		// en plaats dit op de voorlaatste plaats.
		// ...
		// Bij insertion sort hadden we een element en zochten we de plaats
		// waar het moest gezet worden.
		// Bij selection sort overlopen we alle plaatsen en zoeken we het 
		// element dat op deze plaats moet gezet worden.
		unsigned int locMax = i;
		
		for (unsigned int j = 0; j < i; j++){
			if (v[j] > v[locMax]){
				locMax = j;
			}
		}
		T h = v[i];
		v[i] = v[locMax];
		v[locMax] = h;
	} 
}


