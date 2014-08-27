#include <iostream>
#include <fstream>
#include <cstdlib>
#include "chrono.h"

using namespace std;

int max_deelsom(int* rij, int length){
	int max = rij[0];
	for (int i = 0; i < length ; i++){
		int d = 1;
		int som = rij[i];
		while (d < length -i){
			som += rij[i+d];
			if (som > max){
				max = som;
			}
			d++;
		}
	}
	return max;
}
void test(){
	ifstream input;
	input.open("rijen.txt");
	
	while (!input.fail()){
		string lijn;
		input >> lijn;
		
		int length = atoi(lijn.c_str());
		if (length > 0){
		int* rij = new int[length];
		
		for (int i = 0; i < length; i++){
			input >> lijn;
			rij[i] = atoi(lijn.c_str());
		}
		
		input >> lijn;
		int resultaat = atoi(lijn.c_str());
		/*
		cout << "Ik heb " << length << " getallen ingelezen" << endl;
		cout << "[ ";
		for (int i = 0; i < length; i++){
			cout << rij[i] << " ";
		}
		cout << "]" << endl;
		cout << "Het resultaat zou " << resultaat << " moeten zijn" << endl << endl;
		*/
		
		// Maximale deelsom bepalen
		int max = max_deelsom(rij, length);
		
		cout << "De maximale deelsom is " << max;
		if (max == resultaat){
			cout << "\t [OK]" << endl;
		}
		else{
			cout << "\t [FOUT]" << endl;
		}
		
		delete[] rij;
	}
	}
}

void benchmark(int length){
	int* rij = new int[length];
	srand(time(0));
	for (int i = 0; i < length; i++){
		rij[i] = rand() % length;
	}
	
	Chrono c;
	c.start();
	int max = max_deelsom(rij, length);
	c.stop();
	cout << "Het duurde " << c.tijd() << "s om de maximale deelsom (";
	cout << max << " )";
	cout << " te bepalen uit een rij met " << length << " elementen" << endl;
	
}

int main(){
	test();
	cout << endl << endl;
	benchmark(10000);
	cout << endl << endl;
	benchmark(20000);
	cout << endl << endl;
	benchmark(30000);
	cout << endl << endl;
	benchmark(40000);
	cout << "n * 2 -> tijd * 4 (2^2)" <<endl;
	cout << "n * 3 -> tijd * 8 (2^3)" <<endl;
	cout << "n * 4 -> tijd * 16 (2^4)" << endl;
	
	return 0;
}
