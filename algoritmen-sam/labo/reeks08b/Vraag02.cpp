#include <iostream>
#include <vector>
#include <cstdlib>
#include "HashTable2.cpp"
#include "Type1.cpp"

using namespace std;

class Type1Comperator{
	public:
		bool operator()(const Type1 &t1, const Type1 &t2);
};

bool Type1Comperator:: operator() (const Type1 &t1, const Type1 &t2){
	return t1.getString() == t2.getString();
}

class Type1HashcodeGenerator{
	public:
		int operator() (const Type1 &t);
};

int Type1HashcodeGenerator:: operator() (const Type1 &t){
	return t.getString().length();
}

int main(){
	
	Type1Comperator c;
	Type1HashcodeGenerator h;
	
	
	HashTable<Type1, char, Type1Comperator, Type1HashcodeGenerator> table(c,h);
	for (char c ='a' ; c <= 'z'; c++){
		string s = "key ";
		s += c;
		Type1 t(s);
		table.put(t, c);
		s += c;
		Type1 t2(s);
		table.put(t2,c);
	}
	
	Type1 t("key p");
	cout << table.get(t) << endl;
	
	vector<pair<Type1, char> > entries = table.entrySet();
	for (unsigned int i = 0; i < entries.size(); i++){
		cout << entries[i].first.getString() << " : " << entries[i].second << endl;
	}
	table.print();
	cout << ">>> ";
	cin.get();
	return 0;
}
