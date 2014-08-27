#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "SorteerMethode.cpp"

// Heap sort

using namespace std;
template <typename T>
class HeapSort: public SorteerMethode<T>{
	public:
		void operator()(vector<T> &v);
		string getName();
	private:
		void siftDown(vector<T> &v, int start, int end);
		void buildHeap(vector<T> &v);

};

template <typename T>
string HeapSort<T>::getName(){
	return "Heap sort";
}



template <typename T>
void HeapSort<T>::siftDown(vector<T> &v, int start, int end){
	// Laat het element v[start] afdalen in de heap tot het op zijn 
	// plek staat, dus tot we een correcte heap hebben.
	// We gaan niet verder dan end.
	
	// Het element dat nu in de wortel staat moet afdalen
	int toSwap = start;	
	int i = start;
		
	int l = 2*i+1;		// kind 1
	int r = 2*i+2;		// kind 2
	
	if (l <= end && v[i] < v[l]){
		// kind 1 is groter dan de huidige wortel
		toSwap = l;
	}
	if (r <= end && v[toSwap] < v[r]){
		// kind 2 is groter dan de huidige wortel en is ook groter
		// dan kind 1
		toSwap = r;
	}
	
	// doe dit tot het element op zijn plaats staat, dus tot er geen kind
	// meer is dat een grotere waarde heeft.
	while (toSwap != i){
		// Verplaats het element
		swap(v[i],v[toSwap]);
		
		// Het element staat op de nieuwe plaats
		i = toSwap;
		
		l = 2*i+1; // kind 1
		r = 2*i+2; // kind 2
		
		if (l <= end && v[i] < v[l]){
			// kind 1 is groter dan het element
			toSwap = l;
		}
		if (r <= end && v[toSwap] < v[r]){
			// kind 2 is groter dan het element en is ook groter dan 
			// kind 1
			toSwap = r;
		}
			
	}	
}

template <typename T>
void HeapSort<T>::buildHeap(vector<T> &v){
	// Maak een heap van de vector v.
	// We doen dit door steeds heaps samen te voegen.
	// We beginngen met het element met de grootste index dat een kind
	// element heeft.
	int start = (v.size()-2)/2;
	// We gaan omhoog in de heap tot we bij index 0 uitkomen.
	while (start >=0){
		// Telkens laten we het element dat nu in de wortel staat
		// afdalen in zijn subheap tot het op de juiste plaats staat.
		siftDown(v,start,v.size()-1);
		// Ga verder (naar links en dan omhoog) in de heap.
		start--;
		
	}
}


template <typename T>
void HeapSort<T>::operator() (vector<T> &v){
	// Maak een max heap van de vector
	buildHeap(v);
	
	int end = v.size() -1;
	while (end > 0){
		// V[0] is het element met de grootste waarde
		// plaats dit achteraan
		swap(v[end],v[0]);
		end--;
		//Nu hebben we niet noodzakelijk meer een correcte heap
		//Laat het element dat nu op plaats 1 staat afdalen in de boom.
		siftDown(v,0,end);
	}
}


