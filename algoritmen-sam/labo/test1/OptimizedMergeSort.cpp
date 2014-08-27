#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

const int insertionSortLength = 5;

template <typename T>
void insertionSort(vector<T> &v, int start, int stop){
	for (int i = start+1; i <= stop; i++){
		T h = v[i];
		int j = i-1;
		while (j >= start && v[j] > h){
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = h;
	}	
}


template <typename T>
void merge(vector<T> &v, int l, int m , int r, vector<T> &h){
	for (int i = l; i <= m; i++){
		h[i-l] = v[i];
	}
	int pos = l;
	int i = l;
	int j = m+1;
	while (pos <= r && i <= m && j <= r){
		if (h[i-l] < v[j]){
			v[pos] = h[i-l];
			i++;
		}
		else{
			v[pos] = v[j];
			j++;
		}
		pos++;
	}
	
	while (pos <= r && i <= m){
		v[pos] = h[i-l];
		pos++;
		i++;
	}
	while (pos <= r && j <= r){
		v[pos] = v[j];
		pos++;
		j++;
	}
}


template <typename T>
void mergeSortTD(vector<T> &v, int l, int r, vector<T> &h){
	if (r-l <= insertionSortLength){
		insertionSort(v,l,r);
	}
	else{
		int m = l+(r-l)/2;
		mergeSortTD(v,l,m,h);
		mergeSortTD(v,m+1,r,h);
		merge(v,l,m,r,h);
	}
			
}

int min(int a, int b){
	return (a > b ? b : a);
}

template <typename T>
void mergeSortBU(vector<T> &v, vector<T> &h){
	int length = insertionSortLength;
	
	for (int i = 1; i < v.size()-length-1; i+= length){
		insertionSort(v,i,i+length);
	}
	
	while (length < v.size()){
		int i = 0;
		while (i < v.size() -length){			
			merge(v,i,i+length,min(v.size()-1, i+2*length-1),h);
			i += 2*length;
		}		
		length *= 2;
	}	
}

void print(const vector<int> &v){
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}


int main(){
	
	srand(time(0));
	vector<int> v;
	
	
	for (int i = 0; i < 100; i++){
		v.push_back(rand()%10);
	}
	vector<int> v2 (v);
	vector<int> h (v.size());
	
	print(v);	
	mergeSortTD<int>(v,0,v.size()-1,h);	
	print(v);
	
	print(v2);
	mergeSortBU<int>(v2,h);
	print(v2);
	
	
	
	return 0;
}
