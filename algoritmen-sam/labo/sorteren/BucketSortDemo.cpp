#include <iostream>
#include <vector>
#include <cstdlib>
#include "SorteerMethode.cpp"

using namespace std;

template <typename T>
class BucketSort: public SorteerMethode<T>{
	public:
		BucketSort(T _min, T _max);
		BucketSort();
		void operator()(vector<T> &v);
		string getName();
	private:
		T min;
		T max;	
		bool minMaxSet;
		void insertionSort(vector<T> &v);	
		void berekenMinMax(vector<T> &v);
};


template <typename T>
BucketSort<T>::BucketSort(T _min, T _max){
	min = _min;
	max = _max;
	minMaxSet = true;
}

template <typename T>
BucketSort<T>::BucketSort(){
	minMaxSet = false;
}

template <typename T>
string BucketSort<T>::getName(){
	return "Bucket sort";
}

template <typename T>
void BucketSort<T>::insertionSort(vector<T> &v){
	for (int i = 1; i < v.size(); i++){
		T h = v[i];
		int j = i - 1;
	
		while (j >= 0 && v[j] > h){
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = h;
	}
}

template <typename T>
void BucketSort<T>::berekenMinMax(vector<T> &v){
	T tempMin = v[0];
	T tempMax = v[0];
	for (int i = 1;  i < v.size(); i++){
		if (v[i] < tempMin){
			tempMin = v[i];
		}
		else if ( v[i] > tempMax){
			tempMax = v[i];
		}
	}
	min = tempMin;
	max = tempMax;
}

template <typename T>
void BucketSort<T>::operator() (vector<T> &v){
	
	if (!minMaxSet){
		berekenMinMax(v);
	}
	
	// Niet het aantal buckets moet constant zijn maar de belasting per bucket
	// -> aantal elementen in bucket constant.
	
	int n = 10; 				// grootte bucket
	int m = (v.size()/n); 	    // aantal buckets
	int range = ((max - min) / m)+1;
	
	vector<vector<T> > vakken (m);
	for (int i = 0; i < v.size() ; i++){
		int a = (v[i] - min)/range;
		vakken[a].push_back(v[i]);	
	}
	
	
	for (int i = 0; i < vakken.size(); i++){
		// Nu alle vakken overlopen en ze elk sorteren 
		// met insertion sort
		insertionSort(vakken[i]);
	}
	
	// de vakken zijn nu gesorteerd: terug naar oorspronkelijke tabel verplaatsen
	int pos = 0;
	for (int i = 0; i < vakken.size(); i++){
		for (int j = 0; j < vakken[i].size(); j++){
			v[pos] = vakken[i][j];
			pos++;
		}	
	}
		
}

int main(){
	
	srand(time(0));
	
	vector<int> v;
	
	for (int i = 0; i < 50; i++){
		v.push_back(rand());
	}
	
	for (int i = 0; i < v.size(); i++){
		//cout << v[i] << " ";
	}
	cout << endl;
	
	BucketSort<int> b ;
	b(v);
	
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << "OK" <<  endl;
	
	cin.get();
	
	return 0;
}

