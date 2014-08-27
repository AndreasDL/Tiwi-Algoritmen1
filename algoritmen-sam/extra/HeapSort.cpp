#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "SorteerMethode.cpp"
/*
 * Slechte implementatie, er moet niet telkens opnieuw een heap gemaakt worden!!!!
 * */
using namespace std;
template <typename T>
class HeapSort: public SorteerMethode<T>{
	public:
		void operator()(vector<T> &v);
		string getName();
};

template <typename T>
string HeapSort<T>::getName(){
	return "Heap sort (slecht)";
}

template <typename T>
void HeapSort<T>::operator() (vector<T> &v){
	for (unsigned int i = 0; i < v.size(); i++){
		
		// Heap maken van alle elementen behalve de laatste i		
		for (unsigned int j = 1; j < v.size()-i ; j++){
			int k = j;
			int ouder = floor(k/2.0);
			while (k > 0 && v[k] > v[ouder]){

				//T h = v[k];
				//v[k] = v[ouder];
				//v[ouder] = h;
				swap(v[ouder],v[k]);
			
				k = ouder;
				ouder = floor(k/2.0);
			}		
		}	
		
		// Het eerste element is het grootste
		// swappen met het ie laatste element
		//T h = v[0];
		//v[0] = v[v.size() - i-1];
		//v[v.size()-i-1] = h;
		swap(v[0],v[v.size()-i-1]);
	}
}


