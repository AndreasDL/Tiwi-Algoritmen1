#include <iostream>
#include <vector>
#include <cstdlib>
#include "chrono.h"

using namespace std;

#ifndef SORTEERMETHODE
#define SORTEERMETHODE


template <typename T>
class Sorteermethode{
	public:
	virtual double operator()(vector<T> &v)=0;	
};

#endif
