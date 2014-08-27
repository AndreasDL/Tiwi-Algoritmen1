#include <iostream>
#include "Insertionsort.cpp"
#include "Shellsort.cpp"
#include "heapsort.cpp"
#include "Mergesort.cpp"
#include "QuickSort.cpp"
#include "chrono.h"
#include <iomanip>
#include <cstdlib>

using namespace std;

template <typename T>
double Sorteertijd(const vector<T> &v, const Sorteermethode<T> &sort, int ncycli=1){
	double som=0.0;
	for (int i = 0; i< ncycli; i++){
		vector<T> tmp(v);
		Chrono c;
		c.start();
		sort(tmp);
		c.stop();
		som+=c.tijd();
		tmp.clear();
	}
	return som/ncycli;	
}
template<typename T>
void genereerRandomVector(vector<T> &v,int aantalwaarden,int endrange){
	v.clear();
	for(int i=0;i<aantalwaarden;i++){
		int x=rand() % endrange;
		v.push_back(x);
	}
}
template <typename T>
void genereerUpVector(vector<T> &v, int aantalWaarden, int endRange){
	v.clear();
	int factor = 1;
	for (int i=aantalWaarden; i>0; i--){
		v.push_back(endRange-i*factor);
	}
}

template <typename T>
void genereerDownVector(vector<T> &v, int aantalWaarden, int endRange){
	v.clear();
	int factor = 1;
	for (int i=0; i<aantalWaarden; i++){
		v.push_back(endRange-i*factor);
	}
}


template <typename T>
void heap_sort(vector<T> &v){
	int n = v.size();
    while(n > 0){
        maak_heap(v,n);
        swap(v[0],v[n-1]);
       	n--;
    }
}
template <typename T>
void print(vector<T> &v){
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << ", ";
    cout << endl;
}
/*template <typename T>
void merge(vector<T> &v,int l,int m,int r,vector<T> &h){
	int s,i,j;
	s=l;
	i=l;
	j=m+1;
	while((s<=m)&&(j<=r)){
		if(v[s]<=v[j]){
			h[i]=v[s];
			s++;
		}
		else{
			h[i]=v[j];
			j++;
		}
		i++;
	}
	if(s>m){
		for (int k=j;k<=r;k++){
			h[i]=v[k];
			i++;
		}
	}
	else{
		for (int k=s;k<=m;k++){
			h[i]=v[k];
			i++;
		}
	}
	for(int k=l;k<=r;k++){
		v[k]=h[k];
	}
		
}
template <typename T>
void mergesort(vector<T> &v,int l,int r,vector<T> &h){
	if(l<r){
		int m=l+(r-l)/2;
		mergesort(v,l,m,h);
		mergesort(v,m+1,r,h);
		merge(v,l,m,r,h);
	}
}
template <typename T>
void mergesort(vector<T> &v){
	vector<T> h(v.size());
	mergesort(v,0,v.size()-1,h);
}*/



int main(){
	int fac=100000;
	int n=10;
	int end=100;
	int setwText=20;
	int setwGetal=10;
	
	srand(time(0));
	cout << setw(setwGetal) << "Aantal";
	cout << setw(setwText) << "Sorteermethode";
	cout << setw(setwGetal) << "Random";
	cout  << setw(setwGetal) << "Omhoog";
	cout  << setw(setwGetal) << "Omlaag" << endl;
	vector<int> random;
	vector<int> omhoog;
	vector<int> omlaag;
	
	for (int i=1; i<=10; i++){
		int aantal = fac*i;
				
		//random vector bouwen
		genereerRandomVector(random, aantal,end);
	
		//Omhoog gesorteerds
		genereerUpVector(omhoog, aantal, end);
	
		//Omlaag gesorteerd
		genereerDownVector(omlaag, aantal, end);

		//uitvoer
		for (int j=0;j<60;j++)
			cout << "-";
		cout << endl;
		cout << setw(setwGetal) << aantal<<endl;
		/*Insertionsort<int> insertionSort;
		cout << setw(setwGetal) << aantal;
		cout << setw(setwText) << "InsertionSort";
		cout << setw(setwGetal) << Sorteertijd(random, insertionSort, n);
		cout << setw(setwGetal) << Sorteertijd(omhoog, insertionSort, n);
		cout << setw(setwGetal) << Sorteertijd(omlaag, insertionSort, n) << endl;*/

		/*Shellsort<int> shellSort;
		cout << setw(setwGetal) << "";
		cout << setw(setwText) << "ShellSort";
		cout << setw(setwGetal) << Sorteertijd(random, shellSort, n);
		cout << setw(setwGetal) << Sorteertijd(omhoog, shellSort, n);
		cout << setw(setwGetal) << Sorteertijd(omlaag, shellSort, n) << endl;
		
		Heapsort<int> heapsort;
		cout<<setw(setwGetal)<<"";
		cout<<setw(setwText)<<"HeapSort";
		cout << setw(setwGetal) << Sorteertijd(random, heapsort, n);
		cout << setw(setwGetal) << Sorteertijd(omhoog, heapsort, n);
		cout<<setw(setwGetal) << Sorteertijd(omlaag, heapsort, n)<<endl;
		
		Mergesort<int> mergesort;
		cout<< setw(setwGetal)<<"";
		cout<<setw(setwText)<<"Mergesort";
		cout << setw(setwGetal) << Sorteertijd(random, mergesort, n);
		cout << setw(setwGetal) << Sorteertijd(omhoog, mergesort, n);
		cout << setw(setwGetal) << Sorteertijd(omlaag, mergesort, n) << endl;
		*/
		
		QuickSort<int> quickSort;
		cout << setw(setwGetal) << "";
		cout << setw(setwGetal) << "quickSort";
		cout << setw(setwGetal) << Sorteertijd(random, quickSort, n);
		cout << setw(setwGetal) << Sorteertijd(omhoog, quickSort, n);
		cout << setw(setwGetal) << Sorteertijd(omlaag, quickSort, n);
		cout << endl;
		
	}
	/*vector<int> p;
	genereerRandomVector(p,10,50);
	Heapsort<int> heapsort;
	heapsort(p);
	cout<<endl;
	print(p);
	
	/*
	genereerRandomVector(p,20,100);
	print(p);
	Mergesort<int> mergesort;
	mergesort(p);
	print(p);*/
	
	
	cin.get();
	return 0;
}
