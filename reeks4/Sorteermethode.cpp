#include <iostream>
#include <vector>

using namespace std;

#ifndef SORTEERMETHODE
#define SORTEERMETHODE

template <typename T>
class Sorteermethode{
	public:
		virtual void operator()(vector<T> &v) const=0;
};

#endif



