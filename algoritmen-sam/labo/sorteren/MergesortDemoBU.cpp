#include <iostream>
#include <vector>
#include <cstdlib>


using namespace std;

template <typename T>
void merge(vector<T> &v, unsigned int l, unsigned int m, unsigned int r, vector<T> &h){
	cout << "Mergen van v["<<l<<","<<m<<"] en v[" << m+1 << "," << r << "]" << endl;
	// Voeg de deeltabellen v[l,m] en v[m+1,r] (grenzen inclusief) samen
	// tot één gesorteerde deeltabel v[l,r].
	
	// We nemen een kopie van de elementen v[m+1,r]
	for (unsigned int i = l; i <= m; i++){
		h[i-l] = v[i];	
	}
	
	unsigned int i = l;  // huidige index in eerste deeltabel
	unsigned int j = m+1;// huidige index in tweede deeltabel
	unsigned int loc = l;// huidige index in resultaattabel
	
	// Zolang loc <= r zijn er nog elementen die een plaats moeten krijgen
	// Zolang i <= m zijn er nog elementen uit de eerste tabel die een 
	// plaats moeten krijgen.
	// Zolang j <= r zijn er nog elementen uit de tweede tabel die een 
	// plaats moeten krijgen.
	while (loc <= r && i <= m && j <= r){
		if (v[j] < h[i-l]){
			v[loc] = v[j];
			j++;
		}
		else{
			v[loc] = h[i-l];
			i++;
		}
		loc++;	
	}
	// Hier komen we als loc > r: alle elementen zijn geplaatst, dan 
	// moeten de volgende lussen niet uigevoerd worden, of als alle 
	// elementen uit één deeltabel geplaatst zijn maar er nog elementen
	// in de andere deeltabel zijn. We kunnen nu gewoon de andere deeltabel
	// overlopen en ze direct in de resultaattabel plaatsen.
	while (loc <= r && i <= m){
		v[loc] = h[i-l];
		loc++;
		i++;
	}
	while (loc <= r && j <= r){
		v[loc] = v[j];
		loc++;
		j++;
	}
}

int min(int a , int b){
	return (a < b ? a : b);
}

template <typename T>
void mergesort(vector<T> &v, unsigned int l, unsigned int r, vector<T> &h){
	cout << "Sorteren van tabel v["<<l<<","<<r<<"]" << endl;
	unsigned int length = 1;
	while (length < v.size()){
		unsigned int i = 0;
		while (i < v.size() - length){
			merge(v, i, i+length-1, min(i+2*length-1, v.size()-1), h);	
			i = i +2*length;
		}
		length *= 2;
	}
}

template <typename T>
void mergesort(vector<T> &v ){
	// Maak een hulpvector aan.
	vector<T> h(v.size());
	// Start het sorteren op de volledige tabel
	mergesort(v,0, v.size()-1,h);	
}

template <typename T>
void print(vector<T> &v){
	for (unsigned int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(){
	srand(time(0));
	vector<int> v;
	
	for (int i = 0; i < 10; i++){
		v.push_back(rand()%10);
	}
	print<int>(v);
	mergesort<int>(v);
	print<int>(v);
	cout << ">>>";
	cin.get();	
}
