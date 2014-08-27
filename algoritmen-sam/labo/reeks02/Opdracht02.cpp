#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "chrono.h"


using namespace std;

const int size = 10000;



void insertion_sort(vector<int> &v){
	for (unsigned int i = 0; i < v.size(); i++){
		int h = v[i];
		int j = i-1;
		while ( j >= 0 && h < v[j]){
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = h;
	} 
}

void prepare(vector<int> &v, int a){
	for (unsigned int i = 0; i < v.size(); i++){
		int h = v[i];
		int j = i-a;
		while ( j >= 0 && h < v[j]){
			v[j+a] = v[j];
			j--;
		}
		v[j+a] = h;
	} 
}


int main(){
	vector<int> v ;
	srand(time(0));
	for (int i = 0; i < size; i++){
			v.push_back(rand());
	}
	
	cout << "Vector van lengte "<< size << " sorteren" << endl;
	cout << "a\tMet voorsortering\tGewone insertion sort" << endl;
	for (int a = 10; a <= 1000; a*=10){
		vector<int> v1 (v);
		vector<int> v2 (v);
		
		cout << a << "\t";
		Chrono c1;
		c1.start();
				
		prepare(v1,a);
		insertion_sort(v1);
		c1.stop();
		cout << c1.tijd() << "\t\t\t";
	
		Chrono c2;
		c2.start();
		insertion_sort(v2);
		c2.stop();
		cout << c2.tijd() << endl;
	}
	cout << ">";
	cin.get();
	return 0;
	
}
