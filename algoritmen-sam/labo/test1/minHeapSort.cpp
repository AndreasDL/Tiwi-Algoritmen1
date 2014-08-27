#include <iostream>
#include <cstdlib>
#include <vector>


using namespace std;

void daalAf(vector<int> &v, int start, int stop){
	
	int toSwap = start;
	int i = start;
	
	int l = 2*i+1;
	int r = 2*i+2;
	
	if (l <= stop && v[l] < v[toSwap]){
		toSwap = l;
	}
	if (r <= stop && v[r] < v[toSwap]){
		toSwap = r;
	}
	
	while (toSwap != i){
		swap(v[toSwap],v[i]);
		i = toSwap;
		
		l = 2*i+1;
		r= 2*i+2;
	
		if (l <= stop && v[l] < v[toSwap]){
			toSwap = l;
		}
		if (r <= stop && v[r] < v[toSwap]){
			toSwap = r;
		}
	}	
}

void maakMinHeap(vector<int> &v){
	for (int i = (v.size()-2)/2; i >= 0; i--){
		daalAf(v,i,v.size()-1);
	}
}

void print(const vector<int> &v){
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

void heapSort(vector<int> &v){
	int pos = v.size() -1;
	while (pos > 0){
		swap(v[0],v[pos]);
		pos--;
		daalAf(v,0,pos);
	}
}

int main(){

	srand(time(0));
	vector<int> v;
	
	
	for (int i = 0; i < 100; i++){
		v.push_back(rand()%10);
	}
	
	print(v);
	
	maakMinHeap(v);
	print(v);
	heapSort(v);
	print(v);
	
	return 0;
}
