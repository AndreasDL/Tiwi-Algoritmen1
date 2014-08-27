#include <iostream>
#include <vector>
#include <cstdlib>
#include "SorteerMethode.cpp"

// Top down mergesort
// We beginnen met 1 grote tabel en we splitsen die telkens op in
// twee deeltabellen die we afzonderlijk ordenen, daarna voegen we beide
// gesorteerde deeltabellen samen tot 1 grote gesorteerde tabel.

using namespace std;
template <typename T>
class MergeSort: public SorteerMethode<T>{
	public:
		void operator()(vector<T> &v);
		string getName();
	private:
		void merge(vector<T> &v, int l, int m, int r, vector<T> &h);
		void mergesort(vector<T> &v, int l, int r, vector<T> &h);
};

template <typename T>
string MergeSort<T>::getName(){
	return "Merge sort";
}

template <typename T>
void MergeSort<T>::merge(vector<T> &v, int l, int m, int r, vector<T> &h){
	// Voeg de twee deeltabellen v[l,m] en v[m,r] samen.
	
	// Eerste deel kopieren naar hulpvector
	for (unsigned int i = l; i <= m; i++){
		h[i-l] = v[i];	
	}
	
	int i = l; 		// index in eerste tabel
	int j = m+1;    // index in tweede tabel
	int loc = l;    // plaats waar het volgende element moet komen.
	
	// Zolang de tabel niet vol staat en zolang er nog elementen
	// in beide deeltabellen zijn:
	while (loc <= r && i <= m && j <= r){
		// Kijken we welk element het kleinste is
		if (v[j] < h[i-l]){
			// Het element uit de tweede tabel is het kleinste
			v[loc] = v[j];
			j++;
		}
		else{
			// Het element uit de eerste tabel is het kleinste
			// Dit moeten we uit de hulpvector halen.
			v[loc] = h[i-l];
			i++;
		}
		loc++;	
	}
	
	// Als we hier komen, dan is er minsten 1 deeltabel uitgeput
	// We kunnen de overige elementen uit de andere deeltabel gewoon
	// rechtstreeks kopieren naar de resultaatvector.
	// Er zal steeds maximum 1 van onderstaande lussen uitgevoerd worden.
	
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
void MergeSort<T>::mergesort(vector<T> &v, int l, int r, vector<T> &h){
	// Zolang er meer dan 1 element in de deeltabel staat, splitsen
	// we de tabel in twee en passen we mergesort toe op beide delen.
	// Daarna voegen we beide delen samen.
	if (l < r){
		int m = l + (r-l)/2; 	// midden
		mergesort(v, l, m, h);	// sorteer deel 1
		mergesort(v, m+1, r, h);// sorteer deel 2
		merge(v,l,m,r,h);		// voeg samen
	}
}

template <typename T>
void MergeSort<T>::operator() (vector<T> &v){
	// Hulpvector, omdat we telkens mooi in twee splitsen hoeft deze maar
	// half zo groot te zijn als de oorspronkelijke vector.
	vector<T> h(v.size()/2);
	mergesort(v,0, v.size()-1,h);
}


