#include <iostream>
#include "Sorteermethode.cpp"

using namespace std;
#ifndef INSERTIONSORT
#define INSERTIONSORT

template <typename T>
class Insertionsort:public Sorteermethode<T>{
	public:
		void operator() (vector<T> &v) const{
			for(int i=1;i<v.size();i++){
				T h=v[i];
				int j=i-1;
				while(j>=0 && h<v[j]){
					v[j+1]=v[j];
					j--;
				}
				v[j+1]=h;
			}
		}
	
};

#endif
