#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;



bool checkifheap(vector<int> &v){
	for(unsigned int i = v.size()-1; i >=0; i--){
		unsigned int ouder = floor(ouder/2);
		if (v[ouder] < v[i]){
			return false;
		}
	}
	return true;
}
void print(vector<int> &v){
	for (unsigned int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

template <typename T>
bool isGesorteerd(const vector<T> &v){
	for (unsigned int i = 0; i < v.size()-1; i++){
		if (v[i] > v[i+1]){
			return false;
		}
	}
	return true;
}

void siftDown(vector<int> &v, int start, int end){
		int toSwap = start;
		int i = start;
		
		int l = 2*i+1;
		int r = 2*i+2;
		if (l <= end && v.at(i) < v.at(l)){
			toSwap = l;
		}
		if (r <= end && v.at(toSwap) < v.at(r)){
			toSwap = r;
		}
		while (toSwap != i){
			
			swap(v.at(i),v.at(toSwap));
			i = toSwap;
			
			l = 2*i+1;
			r = 2*i+2;
			if (l <= end && v.at(i) < v.at(l)){
				toSwap = l;
			}
			if (r <= end && v.at(toSwap) < v.at(r)){
				toSwap = r;
			}
			
		}	
}

void maakHeap(vector<int> &v){
	int start = (v.size()-2)/2;
	while (start >=0){
		siftDown(v,start,v.size()-1);
		start--;
	}
}

void heapSort(vector<int> &v){
	maakHeap(v);
	int end = v.size() -1;
	while (end > 0){
		swap(v[end],v[0]);
		end--;
		siftDown(v,0,end);
	}
	
}


int main(){
	vector<int> v;
	srand(time(0));
	for (int i = 200000; i >0; i--){
		v.push_back(rand());
	}
	
	heapSort(v);

	
	if (!isGesorteerd(v)){
		cout << "Niet gesorteerd" << endl;
	}
	else{
		cout << "SUCCESSFULL!!!!!" << endl;
	}
	
	return 0;
}















