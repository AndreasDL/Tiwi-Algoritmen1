#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include "chrono.h"

using namespace std;

const int A = 3500;
const int N = 10000;

template <typename T>
class Sorteermethode {
public:
	virtual void operator() (vector<T> &v) const = 0;
};


template <typename T>
class InsertionSort : public Sorteermethode<T> {
public:
	void operator() (vector<T> &v) const{
		for (unsigned int i = 1; i < v.size(); i++){
			T h = v[i];
			int j = i - 1;
			while (j >= 0 && h < v[j]){
				v[j+1] = v[j];
				j--;
			}
			v[j+1] = h;
		}
	}
};

int aantal_kinderen(const int index, const int size){
	int aant = 0;
	if (2*index+2 < size){
		aant = 2;
	}
	else if (2*index+1 < size){
		aant = 1;
	}
	return aant;
}

template <typename T>
class HeapSort : public Sorteermethode<T> {
public:
	void operator() (vector<T> &v) const{
		construeer_heap(v);
		for (int i = 1; i < v.size(); i++){
			swap(v[0], v[v.size()-i]);
			//nieuwe wortel zoeken
			int j = 0;
			while ( (2*j+1 < v.size()-i && v[j] < v[2*j+1]) || (2*j+2 < v.size()-i && v[j] < v[2*j+2]) ){
				int aant = aantal_kinderen(j, v.size()-i);
				int index = 0;
				if (aant == 2){
					index = (v[2*j+1] < v[2*j+2] ? 2*j+2 : 2*j+1);
				}
				else if (aant == 1){
					index = 2*j+1;
				}
				swap(v[j], v[index]);
				j = (index > j ? index : 2*j+1);
			}
			
		}
	}
};

template <typename T>
class STLSort : public Sorteermethode<T> {
public:
	void operator() (vector<T> &v) const{
		sort(v.begin(), v.end());
	}
};

template <typename T>
class ShellSort : public Sorteermethode<T> {
public:
	void operator() (vector<T> &v) const{
		vector<int> incrementen;
		incrementen.push_back(113);
		incrementen.push_back(97);
		incrementen.push_back(61);
		incrementen.push_back(37);
		incrementen.push_back(23);
		incrementen.push_back(11);
		incrementen.push_back(7);
		incrementen.push_back(3);
		incrementen.push_back(1);

		for (int k = 0; k < incrementen.size(); k++){
			for (int i = incrementen[k]; i < v.size(); i++){
				T h = v[i];
				int j = i - incrementen[k];
				while (j >= 0 && h < v[j]){
					v[j+incrementen[k]] = v[j];
					j -= incrementen[k];
				}
				v[j+incrementen[k]] = h;
			}
		}
	}
};

template <typename T>
void merge(vector<T> &v, int l, int m, int r, vector<T> h){
	/*int k = m + 1;
	int aant = 0;
	while (aant < r + 1){
		if (l <= m && v[l] <= v[k]){
			h[aant] = v[l];
			l++;
		}
		else {
			h[aant] = v[k];
			k++;
		}
		aant++;
	}*/
}

template <typename T>
void mergesort(vector<T> &v, int l, int r, vector<T> &h){
	if (l < r){
		int m = l + (r - l) / 2;
		mergesort(v, l, m, h);
		mergesort(v, m+1, r, h);
		merge(v, l, m, r, h);
	}
}

template <typename T>
class MergeSort : public Sorteermethode<T> {
public:
	void operator() (vector<T> &v) const{
		vector<T> h(v.size() / 2);
		mergesort(v, 0, v.size()-1, h);
	}
};


class Punt {
public:
	Punt(int x, int y): _x(x), _y(y){}
	bool operator<(Punt p);
private:
	int _x, _y;
};

bool Punt::operator<(Punt p){
	bool is_kleiner = true;
	if (this->_x > p._x || (this->_x == p._x && this->_y >= p._y)){
		is_kleiner = false;
	}
	return is_kleiner;
}

template <typename T>
void construeer_heap(vector<T> &v){
	for (int i = 1; i < v.size(); i++){
		int huidig = i;
		int ouder = (i - 1) / 2;
		while (huidig > 0 && v[ouder] < v[huidig]){
			swap(v[huidig],v[ouder]);
			huidig = ouder;
			ouder = (huidig - 1) / 2;
		}
	}
}

template <typename T>
double Sorteertijd(const vector<T> &v, const Sorteermethode<T> &sort, int ncycli=1){
	double tijden = 0.0;
	for (int i = 0; i < ncycli; i++){
		vector<T> copy;
		for (unsigned int i = 0; i < v.size(); i++){
			copy.push_back(v[i]);
		}
		Chrono tijd;
		tijd.start();
		sort(copy);
		tijd.stop();
		tijden += tijd.tijd();
	}
	return 1.0 * tijden / ncycli;
}

int main(){
	//test constructie heap + sorteren
	//5;3;1;6;9;7 => 9;6;7;3;5;1
	/*vector<int> v;
	v.push_back(5);
	v.push_back(3);
	v.push_back(1);
	v.push_back(6);
	v.push_back(9);
	v.push_back(7);
	//construeer_heap(v);*/

	/*HeapSort<int> sort;
	sort(v);
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << "; ";
	}
	cout << endl << endl;*/

	srand(time(0));
	//willekeurig
	vector<int> v1;
	for (int i = 0; i < N; i++){
		v1.push_back(rand() % N);
	}

	//alles gelijk
	vector<int> v2;
	for (int i = 0; i < N; i++){
		v2.push_back(1);
	}

	//dalend gesorteerd
	vector<int> v3;
	for (int i = 0; i < N; i++){
		v3.push_back(N-i);
	}

	InsertionSort<int> insertion_sort; //methode 1
	HeapSort<int> heap_sort; //methode 2
	STLSort<int> STLsort; //methode 3
	//ShellSort<int> shell_sort; //methode 4
	MergeSort<int> merge_sort;

	cout << "Willekeurig" << endl;
	cout << setw(10) << "n" << setw(15) << "methode 1" << setw(15) << "methode 2" << setw(15) << "methode 3" << setw(15) << "methode 4" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	for (int i = 100; i <= N; i *= 10){
		vector<int> temp;
		for (int j = 0; j < i; j++){
			temp.push_back(v1[j]);
		}
		cout << setw(10) << i << setw(15) << Sorteertijd(temp, insertion_sort) 
							  << setw(15) << Sorteertijd(temp, heap_sort) 
							  << setw(15) << Sorteertijd(temp, STLsort)
							  << setw(15) << Sorteertijd(temp, merge_sort) << endl;
	}

	cout << endl;
	cout << "Alles gelijk" << endl;
	cout << setw(10) << "n" << setw(15) << "methode 1" << setw(15) << "methode 2" << setw(15) << "methode 3" << setw(15) << "methode 4" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	for (int i = 100; i <= N; i *= 10){
		vector<int> temp;
		for (int j = 0; j < i; j++){
			temp.push_back(v2[j]);
		}
		cout << setw(10) << i << setw(15) << Sorteertijd(temp, insertion_sort) 
							  << setw(15) << Sorteertijd(temp, heap_sort) 
							  << setw(15) << Sorteertijd(temp, STLsort)
							  << setw(15) << Sorteertijd(temp, merge_sort) << endl;
	}

	cout << endl;
	cout << "Dalend gesorteerd" << endl;
	cout << setw(10) << "n" << setw(15) << "methode 1" << setw(15) << "methode 2" << setw(15) << "methode 3" << setw(15) << "methode 4" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	for (int i = 100; i <= N; i *= 10){
		vector<int> temp;
		for (int j = 0; j < i; j++){
			temp.push_back(v3[j]);
		}
		cout << setw(10) << i << setw(15) << Sorteertijd(temp, insertion_sort) 
							  << setw(15) << Sorteertijd(temp, heap_sort) 
							  << setw(15) << Sorteertijd(temp, STLsort)
							  << setw(15) << Sorteertijd(temp, merge_sort) << endl;
	}

	/*vector<int> v;
	for (int i = 0; i < 20; i++){
		v.push_back(rand() % N);
	}

	HeapSort<int> sort;
	sort(v);
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << "; ";
	}
	cout << endl << endl;*/


	cin.get();
	return 0;
}