#include <iostream>
#include <vector>
#include <cstdlib>
#include "SorteerMethode.cpp"

using namespace std;
template <typename T>
class MergeSortBUOptimalisatie: public SorteerMethode<T>{
	public:
		MergeSortBUOptimalisatie(int i);
		void operator()(vector<T> &v);
		string getName();
	private:
		int startSize;
		void merge(vector<T> &v, unsigned int l, unsigned int m, unsigned int r, vector<T> &h);
		void mergesort(vector<T> &v,vector<T> &h);
		void insertionSort(vector<T> &v, unsigned int l, unsigned int r);
		void print(vector<T> &v);
};

template <typename T>
MergeSortBUOptimalisatie<T>::MergeSortBUOptimalisatie(int i){
	startSize = i;
}


template <typename T>
void MergeSortBUOptimalisatie<T>::insertionSort(vector<T> &v, unsigned int l, unsigned int r){
	for (unsigned int i = l+1; i < r; i++){
		T h = v[i];
		unsigned int j = i - 1;
	
		while (j >= l && v[j] > h){
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = h;
	}
}

template <typename T>
string MergeSortBUOptimalisatie<T>::getName(){
	return "Merge srt BU(opt)";
}

template <typename T>
void MergeSortBUOptimalisatie<T>::merge(vector<T> &v, unsigned int l, unsigned int m, unsigned int r, vector<T> &h){
	for (unsigned int i = l; i <= m; i++){
		h[i-l] = v[i];	
	}
	unsigned int i = l;
	unsigned int j = m+1;
	unsigned int loc = l;
	while (loc <= r && i <= m && j <= r){
		if (v[j] < h[i-l]){
			v[loc] = v[j];
			j++;
		}
		else{
			v[loc] = h[i-l];
			i++;
		}
		loc++;	
	}
	
	while (loc <= r && i <= m){
		v[loc] = h[i-l];
		loc++;
		i++;
	}
	while (loc <= r && j <= r){
		v[loc] = v[j];
		loc++;
		j++;
	}
}

template <typename T>
void MergeSortBUOptimalisatie<T>::mergesort(vector<T> &v, vector<T> &h){
	unsigned int length = startSize;
	for (unsigned int i = 0; i <= v.size()-length; i += length){
			cout << "Insertionsort van " << i << " tot " << i+length << endl;
			insertionSort(v,i,i+length);
			print(v);
	}
	
	while (length < v.size()){
		unsigned int i = startSize;
		while (i < v.size() - length){
			merge(v, i, i+length-1, min(i+2*length-1, v.size()-1), h);	
			i = i +2*length;
		}
		length *= 2;
	}
}

template <typename T>
void MergeSortBUOptimalisatie<T>::print(vector<T> &v){
	for (unsigned int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}


template <typename T>
void MergeSortBUOptimalisatie<T>::operator() (vector<T> &v){
	// Maak een hulpvector aan.
	vector<T> h(v.size());
	// Start het sorteren op de volledige tabel
	mergesort(v,h);	
}


int main(){
	srand(time(0));
	vector<int> v;
	for (int i = 0; i < 25; i++){
		v.push_back(rand()%5);
	}
	for (unsigned int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
	
	MergeSortBUOptimalisatie<int> m(5);
	m(v);
	
	
	for (unsigned int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	
	}
	cout << endl;
	
	cin.get();
	return 0;
}
