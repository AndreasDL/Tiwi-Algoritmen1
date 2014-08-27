#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

template <typename T>
class SelectionSort : public Sorteermethode<T>{
	public:
		double operator()(vector<T> &v);	
};

template <typename T>
double SelectionSort<T>::operator()(vector<T> &v){
	Chrono c;
	c.start();
	for (unsigned int i = 0; i < v.size(); i++){
		int index = i;
		for (unsigned int j = i+1; j < v.size(); j++){
			if (v[j] < v[index]){
				index = j;
			}
			
		}			
		swap(v[i],v[index]);
	}
	c.stop();
	return c.tijd();
}

