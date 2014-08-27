#ifndef HASHTABLE
#define HASHTABLE

#include <cstdlib>
#include <vector>
#include <cstdlib>

using namespace std;
template <typename T1, typename T2>
class HashTable{
	private:
		int size;
		static const int m = 2;
		vector<vector<pair<T1,T2> > > data;		
	public:
		HashTable();
		void put(T1 key, T2 value);
		T2 get(T1 key);
		vector<pair<T1, T2> >entrySet();
		void print();
};

template <typename T1, typename T2>
HashTable<T1, T2>::HashTable(){
	size = 0;
	data.resize(m);
}

template <typename T1, typename T2>
void HashTable<T1, T2>::put(T1 key, T2 value){
	int hashcode = key.hashcode();
	int index = hashcode % m;
	pair<T1, T2> p (key, value);
	data[index].push_back(p);	
	size++;
}

template <typename T1, typename T2>
T2 HashTable<T1, T2>::get(T1 key){
	int hashcode = key.hashcode();
	int index = hashcode % m;
	unsigned int i = 0;
	while (i < data[index].size() && !(data[index][i].first.equals(key))){
		i++;
	}
	if (i < data[index].size()){
		return data[index][i].second;
	}
	else{
		return 0;
	}
}

template <typename T1, typename T2>
vector<pair<T1, T2> > HashTable<T1, T2>::entrySet(){
	vector<pair<T1, T2> > entries ;
	for (int i = 0; i < m; i++){
		for (unsigned int j = 0; j < data[i].size(); j++){
			entries.push_back(pair<T1,T2>(data[i][j]));
		}	
	}
	return entries;
}


template <typename T1, typename T2>
void HashTable<T1, T2>::print(){
	for (unsigned int i = 0; i < data.size(); i++){
		cout << i << " ";
		for (unsigned int j = 0; j < data[i].size(); j++){
			cout << data[i][j].first.getString() << " ";
		}
		cout << endl;
	}
}
#endif
