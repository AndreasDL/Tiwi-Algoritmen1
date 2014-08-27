#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "SorteerMethode.cpp"

// Merge sort bottom up
// We beginnen met tabellen van 1 element die dus reeds gesorteerd zijn
// dan voegen we er telkens 2 samen tot we tabellen van twee gesorteerde
// elementen hebben, ...

using namespace std;

template <typename T>
class MergeSortBU: public SorteerMethode<T>{
	public:
		void operator()(vector<T> &v);
		string getName();
	private:
		void merge(vector<T> &v,  int l,  int m,  int r, vector<T> &h);
		void mergesort(vector<T> &v,  int l,  int r, vector<T> &h);
		int min(int a, int b);
};

template <typename T>
string MergeSortBU<T>::getName(){
	return "Merge sort BU";
}

template <typename T>
int MergeSortBU<T>::min(int a, int b){
	return a < b ? a : b;
}

template <typename T>
void MergeSortBU<T>::merge(vector<T> &v,  int l,  int m, int r, vector<T> &h){
	// Voeg de twee gesorteerde deeltabellen
	// v[l,m] en v[m+1,r] samen tot 1 gesorteerde tabel.
	
	// Kopieer de eerste deeltabel naar de hulpvector
	for (unsigned int i = l; i <= m; i++){
		h[i-l] = v[i];	
	}
	
	int i = l;   // startindex eerste deeltabel
	int j = m+1; // startindex tweede deeltabel
	int loc = l; // plaats waar het volgende element moet komen
	
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
void MergeSortBU<T>::mergesort(vector<T> &v, int l, int r, vector<T> &h){
	// We beginnen met tabellen van lengte 1
	int length = 1;
	// We gaan door tot we 1 grote gesorteerde tabel hebben met lengte v.size();
	while (length < v.size()){
		// i is de startindex van de te sorteren deeltabel
		int i = 0;
		while (i < v.size() - length){
			// Voeg de tabellen v[i,i+length-1] 
			// en v[i+2*length-1, eind] samen
			// eind is normaal i+2*length-1 behalve als we aan het einde
			// zitten, we mogen niet voorbij v.size()-1 gaan.
			merge(v, i, i+length-1, min(i+2*length-1, v.size()-1), h);	
			i = i +2*length;
		}
		length *= 2;
	}
}


template <typename T>
void MergeSortBU<T>::operator() (vector<T> &v){
	// Maak een hulpvector aan.
	vector<T> h(v.size());
	// Start het sorteren op de volledige tabel
	mergesort(v,0, v.size()-1,h);	
}


