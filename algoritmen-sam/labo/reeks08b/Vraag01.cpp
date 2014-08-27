#include <iostream>
#include <vector>
#include <cstdlib>
#include "HashTable1.cpp"
#include "Type1.cpp"

using namespace std;

int main(){
	
	HashTable<Type1, char> table;
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
