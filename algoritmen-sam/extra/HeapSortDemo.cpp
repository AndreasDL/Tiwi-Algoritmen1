#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

void maakHeap(vector<int> &v){
	for (unsigned int j = 1; j < v.size() ; j++){
		int k = j;
		int ouder = floor(k/2);
		while (k >= 0 && v[k] > v[ouder]){
			swap(v[ouder],v[k]);		
			k = ouder;
			ouder = floor(k/2);
		}		
	}
}

bool checkifheap(vector<int> &v){
	for(unsigned int i = v.size()-1; i >0; i--){
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

int main(){
	vector<int> v;
	srand(time(0));
	for (int i = 30; i >0; i--){
		v.push_back(rand()%10);
	}
	//print(v);
	
	maakHeap(v);
	if (checkifheap(v)){
		cout << "correcte heap" << endl;
	}
	else {
		cout << "foute heap" << endl;
	}	
	print(v);
	
	
	
	unsigned int end = v.size() -1;
	while (end > 0){
		// De wortel van de boom is het grootste element
		// We moeten dit wisselen met het laatste niet-gesorteerde element.
		
		swap(v[0],v[end]);
		end--;
		
		// Nu hebben we niet noodzakelijk nog een correcte heap
		// We moeten hem herstellen.
		unsigned int j = 0; 
		// Het element dat nu op nul staat moet afdalen in de boom.
		print(v);
	
		// Zolang de root ten minste 1 kind heeft
		
		while (j*2+1  <= end){				
			unsigned int kind = j*2+1;
			unsigned int toswap = j;
			if (v[toswap] < v[kind]){
				toswap = kind;
			}
			if (kind+1 <= end && v[toswap] < v[kind+1]){
				toswap = kind+1;
			}
			if (toswap != j){
				swap(v[j],v[toswap]);
				j = toswap;
			}
			else{
				break;
			}
			print(v);
		}
	}
	
	print(v);
	
	
	if (!isGesorteerd(v)){
		cout << "Niet gesorteerd" << endl;
	}
	else{
		cout << "SUCCESSFULL!!!!!" << endl;
	}
	
	return 0;
}















