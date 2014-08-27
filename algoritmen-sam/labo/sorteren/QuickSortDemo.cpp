#include <iostream>
#include <vector>
#include <cstdlib>


using namespace std;

const int insertionSortLength = 0;

template <typename T>
T geefPivot(vector<T> &v, int l, int r){
	
	
	
	// pivot: uiterste element
	//return v[l]; // pivot linkse element
	//return v[r]; // pivot rechtse element
	
	// random pivot
	// In de code wordt er vanuit gegaan dat de pivot links staat
	// dan zijn er geen extra speciale controles nodig
	//int i = l+rand()%(r-l+1);
	//swap(v[l],v[i]);
	
	// mediaan van 3
	T a = l;
	T b = l+(r-l)/2;
	T c = r;
	
	if (v[a] > v[b])
		swap(v[a],v[b]);
	if (v[b] > v[c])
		swap(v[b],v[c]);
	if (v[a] > v[c])
		swap(v[a],v[c]);
	swap(v[l],v[b]);


	return v[l]; 
	
	
}


template <typename T>
void quicksort(vector<T> &v, int l, int r){
	if (r -l <= insertionSortLength){
		
	}
	else{
		T pivot = geefPivot(v,l,r);	
		int i = l;
		int j = r;
		while (v[j] > pivot){
			j--;
		}
		while (i < j){
			swap(v[i],v[j]);
			i++;
			while (v[i] < pivot){
				i++;
			}
			j--;
			while (v[j] > pivot){
				j--;
			}
		}
		quicksort(v,l,j);
		quicksort(v,j+1,r);
	} 	
}

int main(){
	srand(time(0));
	vector<int> v;
	for (int i = 0; i < 100; i++){
		v.push_back(rand()%10);
	}
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
	quicksort(v, 0, v.size()-1);
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl << ">>>";
	
	cin.get();
	
	return 0;
}
