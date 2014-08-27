#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;



void print(const vector<int> &v){
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

template <typename T>
void quickSort(vector<T> &v, int l, int r){
	if (l < r){
		int i = l;
		int j = r;
		int pivot = v[l+rand()%(r-l)];
		cout << pivot << endl;
		
		while ( i <= j){
			
			while (v[i] <= pivot){
				i++;
			}
			while (v[j] > pivot){
				j--;
			}
			
			if (i <= j){
				swap(v[i],v[j]);
				i++;
				j--;
			}
		}
		
	}
	
}

int main(){
	
	srand(time(0));
	vector<int> v;
	
	
	for (int i = 0; i < 100; i++){
		v.push_back(rand()%10);
	}
	
	print(v);
	quickSort(v,0,v.size()-1);
	print(v);
	
	
	
	return 0;
}

