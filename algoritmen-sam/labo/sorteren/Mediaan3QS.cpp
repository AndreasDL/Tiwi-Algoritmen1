#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "SorteerMethode.cpp"

using namespace std;
 

template <typename T>
class mediaan3QS: public SorteerMethode<T>{
	public:
		mediaan3QS();
		void operator()(vector<T> &v);
		string getName();
	private:
		T geefPivot(vector<T> &v, int l, int r);
		void quicksort(vector<T> &v, int l, int r);
		int insertionSortLength;

};

template <typename T>
mediaan3QS<T>::mediaan3QS(){
	insertionSortLength = 0;
}

template <typename T>
string mediaan3QS<T>::getName(){
	return "mediaan QS";
}


template <typename T>
T mediaan3QS<T>::geefPivot(vector<T> &v, int l, int r){
	T a = l;
	T b = l+(r-l)/2;
	T c = r;
	
	if (v[a] > v[b])
		swap(v[a],v[b]);
	if (v[b] > v[c])
		swap(v[b],v[c]);
	if (v[a] > v[c])
		swap(v[a],v[c]);
	swap(v[l],v[b]);


	return v[l]; 
	
	
}


template <typename T>
void mediaan3QS<T>::quicksort(vector<T> &v, int l, int r){
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
void mediaan3QS<T>::operator() (vector<T> &v){
	quicksort(v, 0, v.size()-1);
}


