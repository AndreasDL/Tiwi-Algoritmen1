#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "chrono.h"

using namespace std;

void insertion_sort(vector<int> &v){
	for (unsigned int i = 0; i < v.size(); i++){
		if (v[i+1] < v[i]){
			unsigned int j = 0;
			int waarde = v[i+1];
			while (j < v.size() && v[j] < waarde ){
				j++;
			}
			for (unsigned int c = i+1; c > j; c--){
				v[c] = v[c-1];
			}
			v[j] = waarde;			
		}
	}
}

int main(){
	// vector v opvullen met random waarden
	vector<int> v;
	srand(time(0));
	for (int i = 0; i < 100000; i++){
		v.push_back(rand() % 1000000);
	}
	// v2 kloon van v
	vector<int> v2 (v);
	
	
	
	// stl sort
	Chrono c;
	c.start();
	sort(v.begin(), v.end());
	c.stop();
	cout << "STL sort: " << c.tijd() << endl;
	
	// insertion sort
	Chrono c2;
	c2.start();
	insertion_sort(v2);
	c2.stop();
	cout << "Insertion sort: " << c2.tijd() << endl;
	
	
	/*for (int i = 0; i < 10; i++){
		v2.push_back(rand() % 10);
	}
	
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	insertion_sort(v2);
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++){
		cout << *it << " ";
	}
	cout << endl;*/
	
	
	
	return 0;
}
