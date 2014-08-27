#include <iostream>
#include <map>
#include <vector>
#include <stdlib.h>
#include "chrono.h"
using namespace std;

const int 

void fillVector(const int aantal, vector<int> &v,int min, int max);
void print(const vector<int> &v);

int main(){    
    //setup
    vector<int> v;
    fillVector(2000000,v,5,1000000);
    
    //algorithm v1.0
    Chrono c;
    c.start();
    map<int,int> aantallen;
    for (int i = 0 ; i < v.size() ; i++){
        aantallen[v[i]]++;
        }
    
    std::map<int, int>::const_iterator it = aantallen.begin();
    int maxAantal = it->second;
    int maxGetal = it->first;
    it++;
    
    while(it != aantallen.end()){
    	int key = it->first;
	    int value = it->second;
        
        if (value > maxAantal){
                  maxAantal = value;
                  maxGetal = key;
        }
        it++;
     }
     c.stop();     
     cout << "methode 1 : max aantal = " << maxAantal << " max getal = mode " << maxGetal << " tijd : " << c.tijd() << endl;
     
    //algoritm v2.0
    c.start();
    std::sort(v.begin(),v.end()); 
    
    int i = 1;
    while ( i < v.size()){
      int huidigGetal=v[0],huidigAantal=1;
      int maxAantal=0,maxGetal;//aantal is zowieso > 0 want aangenomen dat lijst niet leeg is =>indien leeg i = 1  > 0 geen lus
      
      //tel niet huidig
      while (v[i] == huidigGetal){
        huidigAantal++;
        i++;
      }
      
      //indien groter opslaan
      if (huidigAantal > maxAantal){
        maxAantal = huidigAantal;
        maxGetal = huidigGetal;
      }
      
      i++;
    }
    
    c.stop();
    cout << "methode 2 : max aantal = " << maxAantal << " max getal = mode = " << maxGetal << " tijd : " << c.tijd() << endl;
    
    //teardown
    cin.get();
}

void fillVector(const int aantal, vector<int> &v, int min , int max){
  int h  = max - min + 1;
  for (int i = 0 ; i < aantal ; i++){
      v.push_back(rand()%h + min);
  }
}

void print(const vector<int> &v){
     for (int i = 0 ; i < v.size() ; i++){
          cout << v[i] << endl;
          }
}

void preSort(vector<int> &v,const int a){
  for(int i=1; i<v.size(); i++){
  // de i eerste elementen staan reeds in volgorde
    int hulp = v[i]; // we halen het i-de element er uit.
    int j=i-1;
    while(j>=0 && hulp-a<v[j]){
      // alle elementen groter dan het i-de element worden 1 plaats naar rechts opgeschoven
      v[j+1] = v[j];
      j--;
    }
    v[j+1] = hulp; // we voegen het uitgehaalde in op zijn juiste plaats.
  }     
}

void insertion_sort(vector<int> &v){
        for(int i=1; i<v.size(); i++){
                // de i eerste elementen staan reeds in volgorde
                int hulp = v[i]; // we halen het i-de element er uit.
                int j=i-1;
                while(j>=0 && hulp<v[j]){
                        // alle elementen groter dan het i-de element worden 1 plaats naar rechts opgeschoven
                        v[j+1] = v[j];
                        j--;
                }
                v[j+1] = hulp; // we voegen het uitgehaalde in op zijn juiste plaats.
        }
}
