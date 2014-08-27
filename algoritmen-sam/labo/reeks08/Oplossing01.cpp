#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>
#include "chrono.h"

using namespace std;

map<string, vector<string> > anagrammen;

string sorteer_karakters(string woord){
	string word = woord;
	sort(word.begin(), word.end());
	return word;
}

void vul_anagrammen_op(){
	ifstream in("woordenlijst.txt");
	if (!in.is_open()){
		cout << "Fout bij openen woordenlijst" << endl;	
	}
	string woord;
	string sleutel;
	while (!in.fail()){
		in >> woord;
		sleutel = sorteer_karakters(woord);
		anagrammen[sleutel].push_back(woord);
	}
	in.close();	
}

void zoek_anagrammen(){
	ifstream in("bepaal_anagrammen_van.txt");
	if (!in.is_open()){
		cout << "Fout bij openen lijst te zoeken anagrammen" << endl;	
	}
	string woord;
	string sleutel;
	while (!in.fail()){
		in >> woord;
		sleutel = sorteer_karakters(woord);
		cout << woord << endl;
		for (vector<string>::iterator it = anagrammen[sleutel].begin();
			it != anagrammen[sleutel].end(); it++){
				cout << "\t" << *it << endl;
		}
	}
	in.close();		
}


int main(){
	Chrono c;
	c.start();
	cout << "woordenlijst inlezen" << endl;
	vul_anagrammen_op();
	cout << "anagrammen zoeken" << endl;
	zoek_anagrammen();
	c.stop();
	cout << c.tijd() << endl;
	cout << ">>> ";
	cin.get();
	return 0;	
}
