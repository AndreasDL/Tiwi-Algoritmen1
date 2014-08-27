#ifndef HASHTABLE
#define HASHTABLE

#include <cstdlib>
#include <vector>
#include <cstdlib>

using namespace std;
template <typename T1, typename T2, typename comp, typename hashgen>
class HashTable{
	private:
		comp comperator;
		hashgen hashgenerator;
		int size;
		static const int m = 2;
		vector<vector<pair<T1,T2> > > data;		
	public:
		HashTable( comp c, hashgen h);
		void put(T1 key, T2 value);
		T2 get(T1 key);
		vector<pair<T1, T2> >entrySet();
		void print();
};

template <typename T1, typename T2, typename comp, typename hashgen>
HashTable<T1, T2, comp, hashgen>::HashTable(comp c, hashgen h){
	comperator = c;
	hashgenerator = h;
	size = 0;
	data.resize(m);
}

template <typename T1, typename T2, typename comp, typename hashgen>
void HashTable<T1, T2, comp, hashgen>::put(T1 key, T2 value){
	int hashcode = hashgenerator(key);
	int index = hashcode % m;
	pair<T1, T2> p (key, value);
	data[index].push_back(p);	
	size++;
}

template <typename T1, typename T2, typename comp, typename hashgen>
T2 HashTable<T1, T2, comp, hashgen>::get(T1 key){
	int hashcode = hashgenerator(key);
	int index = hashcode % m;
	unsigned int i = 0;
	while (i < data[index].size() && comperator(data[index][i].first, key)){
		i++;
	}
	if (i < data[index].size()){
		return data[index][i].second;
	}
	else{
		return 0;
	}
}

template <typename T1, typename T2, typename comp, typename hashgen>
vector<pair<T1, T2> > HashTable<T1, T2, comp, hashgen>::entrySet(){
	vector<pair<T1, T2> > entries ;
	for (int i = 0; i < m; i++){
		for (unsigned int j = 0; j < data[i].size(); j++){
			entries.push_back(pair<T1,T2>(data[i][j]));
		}	
	}
	return entries;
}


template <typename T1, typename T2, typename comp, typename hashgen>
void HashTable<T1, T2, comp, hashgen>::print(){
	for (unsigned int i = 0; i < data.size(); i++){
		cout << i << " ";
		for (unsigned int j = 0; j < data[i].size(); j++){
			cout << data[i][j].first.getString() << " ";
		}
		cout << endl;
	}
}
#endif
