#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "SorteerMethode.cpp"

using namespace std;
const int insertionSortLength = 0;

template <typename T>
class RandomizedQS: public SorteerMethode<T>{
	public:
		void operator()(vector<T> &v);
		string getName();
	private:
		T geefPivot(vector<T> &v, int l, int r);
		void quicksort(vector<T> &v, int l, int r);

};

template <typename T>
string RandomizedQS<T>::getName(){
	return "Random QS";
}


template <typename T>
T RandomizedQS<T>::geefPivot(vector<T> &v, int l, int r){
	// random pivot
	// In de code wordt er vanuit gegaan dat de pivot links staat
	// dan zijn er geen extra speciale controles nodig
	int i = l+rand()%(r-l+1);
	swap(v[l],v[i]);


	return v[l]; 
	
	
}


template <typename T>
void RandomizedQS<T>::quicksort(vector<T> &v, int l, int r){
	if (r -l <= insertionSortLength){
		
	}
	else{
		T pivot = geefPivot(v,l,r);	
		int i = l;
		int j = r;
		while (v[j] > pivot){
			j--;
		}
		while (i < j){
			swap(v[i],v[j]);
			i++;
			while (v[i] < pivot){
				i++;
			}
			j--;
			while (v[j] > pivot){
				j--;
			}
		}
		quicksort(v,l,j);
		quicksort(v,j+1,r);
	} 	
}



template <typename T>
void RandomizedQS<T>::operator() (vector<T> &v){
	quicksort(v, 0, v.size()-1);
}


