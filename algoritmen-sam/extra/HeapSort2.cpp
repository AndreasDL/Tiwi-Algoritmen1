#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "SorteerMethode.cpp"

using namespace std;
template <typename T>
class HeapSort: public SorteerMethode<T>{
	public:
		void operator()(vector<T> &v);
		string getName();
};

template <typename T>
string HeapSort<T>::getName(){
	return "Heap sort (goed)";
}

template <typename T>
void HeapSort<T>::operator() (vector<T> &v){
	for (unsigned int j = 1; j < v.size() ; j++){
		int k = j;
		int ouder = floor(k/2.0);
		while (k > 0 && v[k] > v[ouder]){
			swap(v[ouder],v[k]);
		
			k = ouder;
			ouder = floor(k/2.0);
		}		
	}
		
	unsigned int end = v.size() -1;
	while (end > 0){
		// De wortel van de boom is het grootste element
		// We moeten dit wisselen met het laatste niet-gesorteerde element.
		
		swap(v[0],v[end]);
		end--;
		
		// Nu hebben we niet noodzakelijk nog een correcte heap
		// We moeten hem herstellen.
		unsigned int j = 0; 
		// Het element dat nu op nul staat moet afdalen in de boom.
		
	
		// Zolang de root ten minste 1 kind heeft
		
		while (j*2+1  <= end){				
			unsigned int kind = j*2+1;
			unsigned int toswap = j;
			if (v[toswap] < v[kind]){
				toswap = kind;
			}
			if (kind+1 <= end && v[toswap] < v[kind+1]){
				toswap = kind+1;
			}
			if (toswap != j){
				swap(v[j],v[toswap]);
				j = toswap;
			}
			else{
				break;
			}
		}
	}
}


	
