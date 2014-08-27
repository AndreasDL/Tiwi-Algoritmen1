#include <iostream>
#include <vector>
#include <cstdlib>
#include "SorteerMethode.cpp"


using namespace std;
template <typename T>
class TelSorteren: public SorteerMethode<T>{
	public:
		void operator()(vector<T> &v);
		string getName();
};

template <typename T>
string TelSorteren<T>::getName(){
	return "telsorteren";
}

template <typename T>
void TelSorteren<T>::operator() (vector<T> &v){
	T min = v[0];
	T max = v[0];
	for (int i = 0; i < v.size(); i++){
		if (v[i] < min)
			min = v[i];
		else if (v[i] > max)
			max = v[i];
	}
	int *freq = new int[max-min];
}

