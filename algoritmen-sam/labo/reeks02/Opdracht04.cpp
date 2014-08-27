#include <iostream>
#include <cstdlib>
#include <utility>
#include <vector>

using namespace std;

const int size = 100;

bool cmp( const pair<int, int> &p1, const pair<int, int> &p2){
	return p1.first < p2.first || 
		( (p1.first == p2.first) && (p1.second < p2.second) );	
}

int main(){
	
	srand(time(0));
	
	vector<pair<int, int> > v (size);
	
	// opvullen vector met size punten
	for (int i = 0; i < size; i++){
			pair<int, int> p ;
			p.first = rand();
			p.second = rand();
			v[i] = p;			
	}
		
	// sorteren
	sort(v.begin(), v.end(), cmp);
	
		
	// controleren
	bool fout = false;
	for (int i = 0 ; i < size-1; i++){
		pair<int, int> p1 = v[i];
		pair<int, int> p2 = v[i+1];
		if ( p1.first > p2.first || ( (p1.first == p2.first) && (p1.second > p2.second) ) ){
			fout = true;
		}
	}
	if (!fout){
		cout << "Correct gesorteerd" << endl;
	}
	else{
		cout << "Fout bij sorteren" << endl;
	}
	
	cin.get();
	return 0;
}
