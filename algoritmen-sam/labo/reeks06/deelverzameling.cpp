#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

void print(const vector<int> &v){
	for (unsigned int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

vector<int>* zoekDeelVerzameling(const vector<int> &bron, int doel){
	int i = bron.size() -1;
	vector<int>* deelverzameling = new vector<int>;
	
	// zolang de waarde groter is dan het doel: verschuif naar links
	while (i >= 0 && bron[i] > doel){
		i--;
	}
	
	int som = 0;
	while (i >= 0 && som != doel){
		som = 0;
		int j = i;
		deelverzameling -> clear();
		
		while (j >= 0 && som < doel){
			if (bron[j] <= doel-som){
				som += bron[j];
				deelverzameling -> push_back(bron[j]);
			}
			j--;
		}
		
		i--;
	}
	
	if (som != doel){
		deelverzameling -> clear();
	}
	
	return deelverzameling;
}


int main(){
	//srand(time(0));
	vector<int> v;
	for (int i = 0; i < 100; i++){
		v.push_back(rand()%1000);
		//v.push_back(i);
	}
	sort(v.begin(), v.end());
	print(v);
	
	int doel = 2566 ;
	
	vector<int>* resultaat = zoekDeelVerzameling(v,doel);
	if (resultaat -> size() == 0){
		cout << "kan deelreeks niet vinden " << endl;
	}
	else{
		cout << "Deelreeks: ";
		int som = 0;
		for (unsigned int i = 0; i < resultaat -> size(); i++){
			som += (*resultaat)[i];
		}
		print(*resultaat);
		cout << "gezocht=" << doel << " gevonden=" << som << endl;
	}
	
	delete resultaat;
	
	return 0;
}
