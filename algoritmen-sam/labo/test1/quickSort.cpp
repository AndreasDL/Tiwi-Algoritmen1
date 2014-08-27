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
	if ( l < r){
		
		int pivot = v[l];
		int i = l;
		int j = r;
	
	
		while (i <= j){
		
			while (v[i] < pivot){
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
	
		if (i > l){
			quickSort(v,l,i-1);
		}
		if (i < r){
			quickSort(v,i,r);
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

