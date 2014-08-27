#include <iostream>
#include <vector>
#include <cstdlib>
#include "SorteerMethode.cpp"
using namespace std;

template <typename T>
class InsertionSort : public Sorteermethode<T>{
	public:
		double operator()(vector<T> &v);	
};

template <typename T>
double InsertionSort<T>::operator()(vector<T> &v){
	Chrono c;
	c.start();
	for (unsigned int i = 0; i < v.size(); i++){
		int h = v[i];
		int j = i-1;
		while ( j >= 0 && h < v[j]){
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = h;
	} 
	c.stop();
	return c.tijd();
}
