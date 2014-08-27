#include <iostream>
#include <vector>
#include <cstdlib>
#include "SorteerMethode.cpp"

using namespace std;
template <typename T>
class MergeSortBUOptimalisatie: public SorteerMethode<T>{
	public:
		MergeSortBUOptimalisatie(int i);
		void operator()(vector<T> &v);
		string getName();
	private:
		int startSize;
		void merge(vector<T> &v, unsigned int l, unsigned int m, unsigned int r, vector<T> &h);
		void mergesort(vector<T> &v, unsigned int l, unsigned int r, vector<T> &h);
		void insertionSort(vector<T> &v, unsigned int l, unsigned int r);
};

template <typename T>
MergeSortBUOptimalisatie<T>::MergeSortBUOptimalisatie(int i){
	startSize = i;
}

template <typename T>
void MergeSortBUOptimalisatie<T>::insertionSort(vector<T> &v, unsigned int l, unsigned int r){
	for (unsigned int i = l; i < r; i++){
		// De eerste 1 elementen zijn reeds gesorteerd
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

template <typename T>
string MergeSortBUOptimalisatie<T>::getName(){
	return "Merge srt BU(opt)";
}

template <typename T>
void MergeSortBUOptimalisatie<T>::merge(vector<T> &v, unsigned int l, unsigned int m, unsigned int r, vector<T> &h){
	for (unsigned int i = l; i <= m; i++){
		h[i-l] = v[i];	
	}
	unsigned int i = l;
	unsigned int j = m+1;
	unsigned int loc = l;
	while (loc <= r && i <= m && j <= r){
		if (v[j] < h[i-l]){
			v[loc] = v[j];
			j++;
		}
		else{
			v[loc] = h[i-l];
			i++;
		}
		loc++;	
	}
	
	while (loc <= r && i <= m){
		v[loc] = h[i-l];
		loc++;
		i++;
	}
	while (loc <= r && j <= r){
		v[loc] = v[j];
		loc++;
		j++;
	}
}

template <typename T>
void MergeSortBUOptimalisatie<T>::mergesort(vector<T> &v, unsigned int l, unsigned int r, vector<T> &h){
	unsigned int length = startSize;
	for (unsigned int i = l; i < r; i += length){
			insertionSort(v,i,i+length);
	}
	
	while (length < v.size()){
		unsigned int i = 0;
		while (i < v.size() - length){
			merge(v, i, i+length-1, min(i+2*length-1, v.size()-1), h);	
			i = i +2*length;
		}
		length *= 2;
	}
}




template <typename T>
void MergeSortBUOptimalisatie<T>::operator() (vector<T> &v){
	// Maak een hulpvector aan.
	vector<T> h(v.size());
	// Start het sorteren op de volledige tabel
	mergesort(v,0, v.size()-1,h);	
}


