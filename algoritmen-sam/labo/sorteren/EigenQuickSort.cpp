#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "SorteerMethode.cpp"

using namespace std;
template <typename T>
class EigenQS: public SorteerMethode<T>{
	public:
		EigenQS();
		void operator()(vector<T> &v);
		string getName();
	private:
		int insertionSortLength;
		void quicksort(vector<T> &v, int start, int end);
		T geefPivot(vector<T> &v, int l, int r);

};

template <typename T>
EigenQS<T>::EigenQS(){
	insertionSortLength = 0;
}

template <typename T>
string EigenQS<T>::getName(){
	return "Eigen Qsort";
}

template <typename T>
T EigenQS<T>::geefPivot(vector<T> &v, int l, int r){
	// De keuze van de pivot bepaalt de efficientie
	
	// pivot: constante index. Dit is de eenvoudigste keuze.
	// We riskeren echter dat we als pivot de maximale of de minimale
	// waarde kiezen zodat we n**2 gedrag krijgen.

	// Zowel het linkse element als het rechtse element als pivot kiezen
	// zorgt voor een slechte performantie bij (omgekeerd) gesorteerde
	// tabellen.
	//return v[l]; // pivot linkse element 
	//return v[r]; // pivot rechtse element
	
	// Het middelste element (of gelijk welk ander element) kiezen
	// beperkt het risico maar sluit een slechte performantie niet uit.
	//return v[l+(r-l)/2]; // pivot middelste element
	
	// bij een random pivot sluiten we nog steeds een slechte performantie
	// niet volledig uit.
	return v[l+rand()%(r-l+1)];
	
	
	// De beste keuze voor de pivot zou de mediaan zijn, dan zijn de deeltabellen
	// steeds even groot. Om de mediaan te weten zou echter de tabel reeds
	// gesorteerd moeten zijn. We maken een schatting van de mediaan
	// door een steekproef van 3 elementen.
	
	T a = l;
	T b = l+(r-l)/2; // niet (l+r)/2, dit zou een overflow kunnen veroorzaken
	T c = r;
	
	if (v[a] > v[b])
		swap(v[a],v[b]);
	if (v[b] > v[c])
		swap(v[b],v[c]);
	if (v[a] > v[b])
		swap(v[a],v[b]);
	
	return v[b]; 
	
	
}


template <typename T>
void EigenQS<T>::quicksort(vector<T> &v, int l, int r){
	//Quicksort werkt ook op basis van opdelen van de tabel in deeltabellen.
	//Deze zijn echter niet van vaste grootte zoals bij mergesort.
	
	// We kiezen een pivot element (methode geefPivot). Dit is een waarde
	// uit de tabel (geen index!).
	// We splitsen de tabel in twee, één deel met de elementen kleiner 
	// dan de pivot en een met de elementen groter dan de pivot.
	// Elementen == pivot mogen in beide helften staan.
	
	// Binnen een deeltabel staan de waarden nog niet in volgorde maar
	// we weten dat als we de deeltabellen kunnen sorteren, dat dan de
	// volledige tabel gesorteerd is. De deeltabellen kunnen we tot het 
	// bittere einde verder met quicksort sorteren of we kunnen overschakelen
	// naar een andere sorteermethode als de deeltabel een zeker lengte
	// bereikt (insertionSortLength);
	
	int i = l;
	int j = r;
	
	if (r -l <= insertionSortLength){
		// De tabellen zijn klein genoeg om met insertionsort te sorteren
		//insertionSort(v,l,r);
	}
	else{
		// pivot waarde
		int pivot = geefPivot(v,l,r);
		
		while (i <= j){
			// eerst volgende element van links te beginnen zoeken dat
			// niet in de juiste deeltabel staat (> pivot)
			while (v[i] < pivot){
				i++;
			}
			// eerst volgende element van rechts te beginnen zoeken dat 
			// niet in de juiste deeltabel staat (< pivot)
			while (v[j] > pivot){
				j--;
			}
			
			if (i <= j){
				swap(v[i],v[j]);
				i++;
				j--;
			}
		}
		
		// De deeltabellen zijn in orde, 
		// v[l,i-1] bevat de elementen <= pivot
		// v[i,r] bevat de elementen >= pivot
		// Beide deeltabellen moeten nu nog gesorteerd worden door een
		// recursieve aanroep van quicksort.
		
		// Controle of we niet buiten de tabel zouden gaan: 
		if ( i > l)
			quicksort(v,l,i-1);
		if (i < r)
			quicksort(v,i,r);
		
		
	} 	
}

template <typename T>
void EigenQS<T>::operator() (vector<T> &v){
	quicksort(v,0,v.size()-1);
}


