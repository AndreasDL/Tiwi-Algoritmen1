#include <iostream>
#include <vector>
#include <cstdlib>
#include "SorteerMethode.cpp"

using namespace std;
template <typename T>
class ShellSort: public SorteerMethode<T>{
	public:
		void operator()(vector<T> &v);
		string getName();
};

template <typename T>
string ShellSort<T>::getName(){
	return "Shell sort";
}

template <typename T>
void ShellSort<T>::operator() (vector<T> &v){
	// Shell sort is gewoon een uitbreiding van insertion sort
	// We beginnen met een zekere k en we zorgen ervoor dat
	// alle waarden die op een afstand k van elkaar staan gesorteerd zijn.
	// k wordt telkens kleiner tot k = 1 -> insertion sort
	
	int k = v.size()/2;
	while (k >= 1){
		// Het is niet enkel element 0,k,2k, ...
		// dat we moeten sorteren maar ook 1, k+1, 2k+1, ...
		for (unsigned int i = k ; i < v.size(); i++){
			int h = v[i];
			int j = i-k;
			while (j >= 0 && v[j] > h){
				v[j+k] = v[j];
				j -= k;
			}
			v[j+k] = h;			
		}	
		k /= 2;
	}
}


