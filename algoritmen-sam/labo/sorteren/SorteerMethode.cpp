#include <vector>

#ifndef SORTEERMETHODE
#define SORTEERMETHODE

using namespace std;

template <typename T>
class SorteerMethode{
	public:
		virtual void operator() (vector<T> &v) = 0;
		virtual string getName() = 0;
	
};

#endif
