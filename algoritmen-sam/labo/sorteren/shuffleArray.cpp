#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

/*random shuffle van array
	- random index bepalen -> waarde op deze index omwisselen met laatste waarde
	- random index bepalen tussen 0 en lengte -1> waarde op deze index omwisselen met voorlaatste waarde
*/

template <typename T>
void shuffle( T* array, int size){
	srand(time(0));
	for (int i = size; i > 0; i--){
		int index = rand() % i;
		swap(array[index], array[i-1]);	
	}
}

template <typename T>
void shuffle( vector<T> &v){
	srand(time(0));
	for (int i = v.size(); i > 0; i--){
		int index = rand() % i;
		swap(v[index], v[i-1]);	
	}
}

/*
int main(){
	int array[10];
	for (int i = 0; i < 10; i++){
		array[i] = i;
	}
	shuffle<int>(array,10);
	for (int i = 0; i < 10; i++){
		cout << array[i] << " ";
	}
	cout << endl;
	cin.get();
	return 0;
}
*/
