#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "Lijst.cpp"
#include "chrono.h"

using namespace std;
using namespace Lijsten;

void insertion_sort(vector<int> &v){
	for (unsigned int i = 1; i < v.size(); i++){
		int h = v[i];
		int j = i - 1;
		while (j >= 0 && h < v[j]){
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = h;
	}
}

int som(vector<int> &v){
	int som = 0;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
		som += *it;
	}
	return som;
}

int main(){
	srand(time(0));

	//oef 1
	/*Lijst<int> l1;
	l1.voeg_toe_vooraan(7);
	l1.voeg_toe_vooraan(5);
	l1.voeg_toe_vooraan(4);
	l1.voeg_toe_vooraan(2);
	l1.voeg_toe_vooraan(1);

	l1.voeg_toe_vooraan(1);
	l1.voeg_toe_vooraan(4);
	l1.voeg_toe_vooraan(2);

	l1.voeg_toe_vooraan(71);
	l1.voeg_toe_vooraan(5);
	l1.voeg_toe_vooraan(14);
	l1.voeg_toe_vooraan(32);
	l1.voeg_toe_vooraan(1);

	l1.toon_elementen();
	l1.insertion_sort();
	l1.toon_elementen();

	//cout<<l1.zoek_gerangschikt(10)->getFirstValue()<<endl;
	//cout<<l1.zoek_gerangschikt(0)->getFirstValue()<<endl;
	//cout<<l1.zoek_gerangschikt(3)->getFirstValue()<<endl;*/


	//oef2
	/*
	vector<int> v;
	for (int i = 0; i < 10000; i++){
		v.push_back(rand() * 1000);
	}
	vector<int> v2(v);
	Chrono c;
	c.start();
	insertion_sort(v2);
	c.stop();
	for (int i = 0; i < 10; i++){
		cout << v2[i] << " ";
	}
	cout << endl << "tijd: " << c.tijd() << endl << endl;

	vector<int> v3(v);
	Chrono c2;
	c2.start();
	sort(v3.begin(), v3.end());
	c2.stop();
	for (int i = 0; i < 10; i++){
		cout << v3[i] << " ";
	}
	cout << endl << "tijd: " << c2.tijd() << endl << endl;*/


	//oef3
	const int SIZE = 10000;
	vector<vector<int> > reeksen(SIZE);
	for (int i = 0; i < SIZE; i++){
		int lengte = rand() % 1000 + 1;
		for (int j = 0; j < lengte; j++){
			reeksen[i].push_back(rand() % 201 - 100);
		}
	}

	Chrono c3;
	c3.start();
	int max = som(reeksen[0]);
	for (unsigned int i = 0; i < reeksen.size(); i++){
		int sum = som(reeksen[i]);
		if (sum > max){
			max = sum;
		}
	}
	c3.stop();
	cout << "max: " << max << endl << "tijd: " << c3.tijd() << endl;

	cin.get();
	return 0;
}