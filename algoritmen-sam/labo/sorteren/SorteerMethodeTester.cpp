#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <iomanip>
#include "chrono.h"

#include "shuffleArray.cpp"

#include "SorteerMethode.cpp"
#include "InsertionSort.cpp"
#include "ShellSort.cpp"
#include "SelectionSort.cpp"
#include "HeapSort.cpp"
#include "Mergesort.cpp"
#include "StlSort.cpp"
#include "MergeSortBU.cpp"
#include "MergeSortBUOptimalisatie.cpp"
#include "RandomizedQuickSort.cpp"
#include "Mediaan3QS.cpp"
#include "EigenQuickSort.cpp"
#include "SelftestTest.cpp"
#include "BucketSort.cpp"


using namespace std;

const int minSize = 100;
const int maxSize = 10000000;
vector<SorteerMethode<int>* > methodes;

template <typename T>
double sorteertijd(vector<T> &v, SorteerMethode<T>* methode, int ncycli=1){
	double somTijden = 0.0;
	for (int i = 0; i < ncycli; i++){
		vector<T> kopie (v);
		Chrono c;
		c.start();
		(*methode)(kopie);
		c.stop();
		somTijden += c.tijd();
	}
	return somTijden / ncycli;
	
}

void testOmgekeerdeVolgorde(){
	cout << "* Vector in omgekeerde volgorde" << endl;
	cout << setw(10) << "grootte";
	for (vector<SorteerMethode<int>* >::iterator it = methodes.begin();
			it != methodes.end(); it++){
			cout << setw(20) << (*it) -> getName() ;			
	}
	cout << endl;
	for (int i = minSize ; i < maxSize+1; i*=10){
		vector<int> v;
		for (int j = 0; j < i; j++){
			v.push_back(i-j);
		}		
		cout << setw(10) << i;
		for (vector<SorteerMethode<int>* >::iterator it = methodes.begin();
			it != methodes.end(); it++){
			cout << setw(20) << sorteertijd(v, *it);			
		}
		cout << endl;
	}
}

void testGesorteerd(){
	cout << "* Vector in gesorteerde volgorde" << endl;
	cout << setw(10) << "grootte";
	for (vector<SorteerMethode<int>* >::iterator it = methodes.begin();
			it != methodes.end(); it++){
			cout << setw(20) << (*it) -> getName() ;			
	}
	cout << endl;
	for (int i = minSize ; i < maxSize+1; i*=10){
		vector<int> v;
		for (int j = 0; j < i; j++){
			v.push_back(j);
		}		
		cout << setw(10) << i;
		for (vector<SorteerMethode<int>* >::iterator it = methodes.begin();
			it != methodes.end(); it++){
			cout << setw(20) <<  sorteertijd(v, *it);		
		}
		cout << endl;
	}
}

void testWillekeurig(){
	cout << "* Vector in random volgorde" << endl;
	cout << setw(10) << "grootte";
	for (vector<SorteerMethode<int>* >::iterator it = methodes.begin();
			it != methodes.end(); it++){
			cout << setw(20) << (*it) -> getName() ;			
	}
	cout << endl;
	for (int i = minSize ; i < maxSize+1; i*=10){
		vector<int> v;
		for (int j = 0; j < i; j++){
			v.push_back(rand());
		}
		shuffle<int>(v);
		cout << setw(10) << i;
		for (vector<SorteerMethode<int>* >::iterator it = methodes.begin();
			it != methodes.end(); it++){
			cout << setw(20) << sorteertijd(v, *it);			
		}
		cout << endl;
	}
}

template <typename T>
bool isGesorteerd(const vector<T> &v){
	for (unsigned int i = 0; i < v.size()-1; i++){
		if (v[i] > v[i+1]){
			return false;
		}
	}
	return true;
}

bool zelfdeFrequenties(map<int,int> &freq, vector<int> &v){
	map<int, int> test;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
		test[*it]++;
	}
	/*for (map<int,int>::iterator it = freq.begin(); it != freq.end(); it++){
		cout << it -> first << " : " << it -> second << endl;
	}
	for (map<int,int>::iterator it = test.begin(); it != test.end(); it++){
		cout << it -> first << " : " << it -> second << endl;
	}*/
	for (map<int,int>::iterator it = freq.begin(); it != freq.end(); it++){
		if (it -> second != test[it -> first]){
			return false;
		}
	}
	return true;
}

bool selfTest(){
	bool success = true;
	vector<int> v;
	for (int i = 0; i < 5000; i++){
		v.push_back(rand());
	}
	
	cout << "* Controle sorteermethodes" << endl;
	// aanmaken frequentietabel
	map<int,int> freq;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
		freq[*it]++;
	}
	
	
	for (vector<SorteerMethode<int>* >::iterator it = methodes.begin();
			it != methodes.end(); it++){
			cout << setw(20) << (*it) -> getName();
			vector<int> kopie (v);
			(**it)(kopie);
			if ( isGesorteerd(kopie) && zelfdeFrequenties(freq,kopie)){
				cout << " [OK]";
			}
			else{
				cout << " [FAILED]";
				success = false;
			}
			cout << endl;			
	}
	return success;
}


int main(){
	srand(time(0));
	
	//methodes.push_back(new StlSort<int>);
	//methodes.push_back(new InsertionSort<int>);
	//methodes.push_back(new ShellSort<int>);
	//methodes.push_back(new SelectionSort<int>);
	//methodes.push_back(new HeapSort<int>);
	//methodes.push_back(new MergeSort<int>);
	//methodes.push_back(new MergeSortBU<int>);
	//methodes.push_back(new MergeSortBUOptimalisatie<int>(20));
	//methodes.push_back(new RandomizedQS<int>());
	//methodes.push_back(new mediaan3QS<int>());
	//methodes.push_back(new EigenQS<int>());
	//methodes.push_back(new SelfTestTest<int>());
	methodes.push_back(new BucketSort<int>());
	
	if (!selfTest()){
		cout << "Selftest failed" << endl;
		cin.get();
		return 1;
	}
	cout << endl << endl;
	
		
	testWillekeurig();
	cout << endl << endl;
	testGesorteerd();
	cout << endl << endl;
	testOmgekeerdeVolgorde();
	cout << endl << endl;
	
	for (vector<SorteerMethode<int>* >::iterator it = methodes.begin();
			it != methodes.end(); it++){
			delete *it;			
	}
	
	cout << ">>>";
	cin.get();
	return 0;
}
