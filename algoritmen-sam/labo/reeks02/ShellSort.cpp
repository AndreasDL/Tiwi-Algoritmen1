#include <iostream>
#include <vector>
#include <cstdlib>
#include "SorteerMethode.cpp"

using namespace std;

template <typename T>
class ShellSort : public Sorteermethode<T>{
	public:
		double operator()(vector<T> &v);
	private:
		void shellsort( vector<T> &v);	
};

template <typename T>
double ShellSort<T>::operator()(vector<T> &v){
	Chrono c;
	c.start();

	shellsort(v);
		
	c.stop();
	return c.tijd();
}

template <typename T>
void ShellSort<T>::shellsort( vector<T> &v){
	int k = v.size()/2;
	while ( k >= 1){
		for (int i = k; i < v.size(); i++){
			int h = v[i];
			int j = i-k;
			while (j >= 0 && h > v[j]){
				v[j+k] = v[j];
				j -= k;
			}
			v[j+k] = h;
		}
		k /=3;				
	}
}
