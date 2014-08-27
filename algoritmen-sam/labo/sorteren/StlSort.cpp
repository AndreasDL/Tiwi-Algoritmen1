#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "SorteerMethode.cpp"

using namespace std;
template <typename T>
class StlSort: public SorteerMethode<T>{
	public:
		void operator()(vector<T> &v);
		string getName();
};

template <typename T>
string StlSort<T>::getName(){
	return "Stl sort";
}

template <typename T>
void StlSort<T>::operator() (vector<T> &v){
	sort(v.begin(),v.end());
}


