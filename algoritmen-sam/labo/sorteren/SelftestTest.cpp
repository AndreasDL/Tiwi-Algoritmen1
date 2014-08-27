#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "SorteerMethode.cpp"

// Deze klasse wordt gebruikt om de tester te testen

using namespace std;
template <typename T>
class SelfTestTest:public SorteerMethode<T>{
	public:
		void operator()(vector<T> &v);
		string getName();
};

template <typename T>
string SelfTestTest<T>::getName(){
	return "test tester";
}

template <typename T>
void SelfTestTest<T>::operator() (vector<T> &v){
	for (unsigned int i = 0; i < v.size(); i++){
		v[i] = 8989;
	}
}


