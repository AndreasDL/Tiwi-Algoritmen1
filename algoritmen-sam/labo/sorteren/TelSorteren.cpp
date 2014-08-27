#include <iostream>
#include <vector>
#include <cstdlib>
#include "SorteerMethode.cpp"


using namespace std;
template <typename T>
class TelSorteren: public SorteerMethode<T>{
	public:
		void operator()(vector<T> &v);
		string getName();
};

template <typename T>
string TelSorteren<T>::getName(){
	return "telsorteren";
}

template <typename T>
void TelSorteren<T>::operator() (vector<T> &v){
	T min = v[0];
	T max = v[0];
	for (unsigned int i = 0; i < v.size(); i++){
		if (v[i] < min)
			min = v[i];
		else if (v[i] > max)
			max = v[i];
	}
	cout << max-min << endl;
	int *freq = new int[max-min];
	for (int i = 0; i< v.size(); i++){
		freq[v[i]-min]++;
	}
	for (int i = v.size()-1; i > 0; i--){
		// positie bepalen waar het moet komen
		int pos = -1;
		for (int j = 0; j <= v[i]-min; j++){
			pos += freq[j];
		}
		swap(v[pos],v[i]);
	}
	delete[] freq;
}

int main(){
	TelSorteren<int> t;
	vector<int> v;
	srand(time(0));
	for (int i = 0; i < 100; i++){
		v.push_back(rand()%10);
	}
	t(v);
	return 0;
}

