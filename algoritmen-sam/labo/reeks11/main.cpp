#include "ggraaf.h"
#include "dijkstra.h"
#include "simpleunittest.h"
#include "dijkstratest.h"

#include <iostream>
using namespace std;

int main(){
	Dijkstra<int> dijkstra;
	test_dijkstra();
	cin.get();
	return 0;
}
