#include <iostream>
#include <vector>
#include "sortMethod.h"
#include "sorteerTijd.h"
using namespace std;

const int AANTAL = 1000000;
const int MAX = 100000;
const int MIN = 0;
const int CYCLI = 1;

void fillVectors(const int aantal,const int max, const int min,vector<int> &sorted,vector<int> &scrambled,vector<int> &reverse);
void print(const vector<int> &v);

int main(){
  //setup
  //aanmaken
  vector<int> a(AANTAL);
  vector<int> b(AANTAL);
  vector<int> c(AANTAL);
  
  //fill
  fillVectors(AANTAL,MAX,MIN,a,b,c);
  cout << "prepping complete" << endl;
  
  //tests
  const InsertionSort ins;
  const ShellSort shl;
  const HeapSort hst;
  
  cout << "method CYCLI: " << CYCLI << " time: "  << sorteerTijd(a,ins,CYCLI) << endl;
  cout << "method CYCLI: " << CYCLI << " time: "  << sorteerTijd(a,shl,CYCLI) << endl; 
  cout << "method CYCLI: " << CYCLI << " time: "  << sorteerTijd(a,hst,CYCLI) << endl; 
  
  
  //tear down
  
  cin.get();
  return 0;
}

void fillVectors(const int aantal,const int max, const int min,vector<int> &sorted,vector<int> &scrambled,vector<int> &reverse){
  int hulp = max-min+1;
  sorted.clear();
  scrambled.clear();
  reverse.clear();
  
  //maak 3 keer een random
  for (int i = 0 ; i < aantal ; i++){
    int temp = rand()%hulp+min;
      sorted.push_back(temp);
      scrambled.push_back(temp);
  }
  
  //sorteer de eerste
  for(int i=1; i<sorted.size(); i++){
    // de i eerste elementen staan reeds in volgorde
    int hulp = sorted[i]; // we halen het i-de element er uit.
    int j=i-1;
    while(j>=0 && hulp<sorted[j]){
            // alle elementen groter dan het i-de element worden 1 plaats naar rechts opgeschoven
            sorted[j+1] = sorted[j];
            j--;
    }
    sorted[j+1] = hulp; // we voegen het uitgehaalde in op zijn juiste plaats.
  }
  
  //de tweede is al scrambled
  
  //laatste = eerste omgekeerd
  for (int i = sorted.size() -1 ; i >=0 ; i--){
    reverse.push_back(sorted[i]);
  }
}

void print(const vector<int> &v){
  cout << "size : " << v.size() << endl << endl;
  for (int i = 0 ; i < v.size() ; i++){
      cout << v[i] << endl;
      }
      
  cout << endl;
}
