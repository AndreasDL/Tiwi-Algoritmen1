#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include "chrono.h"
#include "InsertionSort.cpp"
#include "SelectionSort.cpp"
#include "ShellSort.cpp"
using namespace std;

const int startSize = 100;
const int stopSize = 10000;



template <typename T>
double Sorteertijd(vector<T> &v, Sorteermethode<T> &sort, int ncycli=1){
	double* tijden = new double[ncycli];
	double som = 0.0;
	for (int i = 0; i < ncycli; i++){
		tijden[i] = (sort) (v);
		som += tijden[i];
	}
	delete tijden;
	return som/ncycli;
}

int main(){
	InsertionSort<int> methode1 ;
	SelectionSort<int> methode2;
	ShellSort<int> methode3;
	srand(time(0));
	cout << setw(10) << "Size" << setw(20) << "Insertion sort";
	cout << setw(15) << "Selection sort" ;
	cout << setw(15) << "Shell sort" << endl;
	cout << "-------------------------------------------------------" << endl << endl;
	
	cout << "* Vector reeds in volgorde" << endl;
	for (int size = startSize; size <= stopSize; size *=10){
		vector<int> v (size);
		for (int i = 0; i < size; i++){
			v.push_back(i);
		}
	
		cout << setw(10) << size;
		cout << setw(15) << Sorteertijd(v, methode1);
		//cout << setw(15) << Sorteertijd(v, methode2);
		cout << setw(15) << "****";
		cout << setw(15) << Sorteertijd(v, methode3);
		cout << endl;
	}
	
	cout << "* Vector in omgekeerde volgorde" << endl;
	for (int size = startSize; size <= stopSize; size *=10){
		vector<int> v (size);
		for (int i = size ; i >0 ; i--){
			v.push_back(size-1);
		}
	
		cout << setw(10) << size;
		cout << setw(15) << Sorteertijd(v, methode1);
		//cout << setw(15) << Sorteertijd(v, methode2);
		cout << setw(15) << "****";
		cout << setw(15) << Sorteertijd(v, methode3);
		cout << endl;
	}
	
	cout << "* Willekeurige vector" << endl;
	for (int size = startSize; size <= stopSize; size *=10){
		vector<int> v (size);
		for (int i = 0; i < size; i++){
			v.push_back(rand());
		}
	
		cout << setw(10) << size;
		cout << setw(15) << Sorteertijd(v, methode1);
		//cout << setw(15) << Sorteertijd(v, methode2);
		cout << setw(15) << "****";
		cout << setw(15) << Sorteertijd(v, methode3);
		cout << endl;
	}

	cout << ">>> ";
	cin.get();
	return 0;
}
