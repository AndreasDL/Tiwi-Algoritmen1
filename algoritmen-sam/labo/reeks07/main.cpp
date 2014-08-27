#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include "knoop.cpp"


using namespace std;

map<char, bool> operatoren;
map<char, int> aantal_operanden;


void init_operatoren(){
	operatoren['*'] = false;
	operatoren['@'] = true;
	operatoren['-'] = false;
	operatoren['+'] = false;
	operatoren['!'] = true;
	operatoren['/'] = false;
	operatoren['%'] = false;
	
	aantal_operanden['*'] = 2;
	aantal_operanden['@'] = 1;
	aantal_operanden['-'] = 2;
	aantal_operanden['+'] = 2;
	aantal_operanden['!'] = 1;
	aantal_operanden['/'] = 2;
	aantal_operanden['%'] = 2;
	
}

knoop* verwerk(vector<char> v){
	knoop *wortel = new knoop(0,v[0]);
	knoop *laatste = wortel;
	for (unsigned int i = 1; i < v.size(); i++){
		if (operatoren.find(v[i])  != operatoren.end()){
			// v[i] is een operator
			knoop *k = new knoop(laatste, v[i]);
			laatste -> voeg_kind_toe(k);
			//cout << "kind " << v[i] << " toegevoegd bij ouder " << laatste -> getWaarde() << endl;
			laatste = k;
		}
		else{
			laatste -> voeg_kind_toe(new knoop(laatste, v[i]));
			//cout << "kind " << v[i] << " toegevoegd bij ouder " << laatste -> getWaarde() << endl;
		}
		while (laatste != 0 && laatste -> getAantalKinderen() == aantal_operanden[laatste -> getWaarde()]){
			laatste = laatste -> getOuder();
		}
	}
	return wortel;
		
}

vector<char> reverse_string(string s){
	vector<char> chars(s.length());
	for (unsigned int i = 0; i< s.length(); i++){
		chars[s.length()-i-1] = s[i];
	}
	
	return chars;
}



int main(){
	
	init_operatoren();
	
	ifstream in("formules_poolse_notatie.txt");
	if (! in.is_open()){
		cout << "fout bij openen bestand" << endl;
		return 1;
	}
	int max = 1000;
	int cnt = 0;
	string input;
	while (! in.fail() && cnt < max){
		in >> input;
		vector<char> karakters = reverse_string(input);
		knoop* wortel = verwerk(karakters);
		cout << wortel -> toString() << endl;
		delete wortel;
		cnt++;
	}
	cout << ">>> " ;
	in.close();
	cin.get();
	return 0;
}



