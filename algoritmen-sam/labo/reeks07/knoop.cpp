#include "knoop.h"
#include <string>
#include <vector>
#include <map>

map<char, int> volgorde;

knoop::knoop(knoop *_ouder, char _waarde){
	ouder = _ouder;
	waarde = _waarde;
	
	// 1 -> eerst
	// 2 -> midden
	// 3 -> achteraan
	volgorde['*'] = 2;
	volgorde['@'] = 1;
	volgorde['-'] = 2;
	volgorde['+'] = 2;
	volgorde['!'] = 3;
	volgorde['/'] = 2;
	volgorde['%'] = 2;
}

string knoop::toString(){
	string out;
	if (volgorde.find(waarde) != volgorde.end() && volgorde[waarde] == 1){
		//cout << waarde << " op eerste plaats " << endl;
		out+=waarde;
	}
	if (kinderen.size() != 0){
		out+="(";
	}

	
	if (kinderen.size() > 1){
		out += kinderen[1]->toString(); 
	}
	
	if (volgorde.find(waarde) != volgorde.end() && volgorde[waarde] == 2){
		out+=waarde;
	}
	else if (volgorde.find(waarde) == volgorde.end()){
		out+=waarde;
	}
	
	if (kinderen.size() > 0){
		out+=kinderen[0]->toString();
	}
	
	if (volgorde.find(waarde) != volgorde.end() && volgorde[waarde] == 3){
		out+=waarde;
	}
	
	if (kinderen.size() != 0){
		out+=")";
	}
	return out;
}

void knoop::voeg_kind_toe(knoop* kind){
	kinderen.push_back(kind);	
}

knoop::~knoop(){
	for (unsigned int i =0; i<kinderen.size(); i++){
		delete kinderen[i];
	}
}

int knoop::getAantalKinderen(){
	return kinderen.size();
}

knoop* knoop::getOuder(){
	return ouder;
}
char knoop::getWaarde(){
	return waarde;
}
