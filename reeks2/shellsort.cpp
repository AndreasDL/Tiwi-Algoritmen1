#include <iostream>
#include <vector>
#include "chrono.h"
using namespace std;

void fillVector(const int aantal, vector<int> &v,const int min,const int max);
void print(const vector<int> &v);
void preSort(vector<int> &v,const int a);
void insertionSort(vector<int> &v);
void copyVector(const vector<int> &in,vector<int> &uit);
void shuffleVector(vector<int> &v);
void shellSort(vector<int> &v);
bool isSorted(const vector<int> &v);


int main(){
  vector<int> v;
  fillVector(1000000,v,0,1000000);
  
  Chrono c;
  c.start();
  shellSort(v);
  c.stop();
  
  cout << "aantal: " << v.size() << " tijd: " << c.tijd()  << " result: " << (isSorted(v)==1 ? "good" : "bad") << endl;
  
  cin.get();
  return 0;  
}
void shellSort(vector<int> &v){
  cout << "shellSortStart" << endl;
  
  //waarden maken
  vector<int> waarden;
  int hulp = v.size()/2;
  while(hulp > 0){
    waarden.push_back(hulp);
    hulp=hulp/2;
    }
    
  for (int i = 0 ; i < waarden.size() ; i++){
    preSort(v,waarden[i]);
    cout << "progress: " << waarden[i] << endl;
  }
}
  
void fillVector(const int aantal, vector<int> &v,const int min ,const int max){
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
    int j=i-a;
    while(j>=0 && hulp<v[j]){
      // alle elementen groter dan het i-de element worden 1 plaats naar rechts opgeschoven
      v[j+a] = v[j];
      j-=a;
    }
    v[j+a] = hulp; // we voegen het uitgehaalde in op zijn juiste plaats.
  }     
}

void insertionSort(vector<int> &v){
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

void copyVector(const vector<int> &in, vector<int> &uit){
   for (int i = 0 ; i < in.size() ; i++){
       uit.push_back(in[i]);
   }
}

bool isSorted(const vector<int> &v){
      int i = 0;
      while (i < v.size() && v[i] <= v[i]+1){
            i++;
      }
      return i == v.size();    
}

void shuffleVector(vector<int> &v){
     for (int i = 0 ; i < v.size() ; i++){
       //2 random indexen
       int begin = rand() % v.size();
       int einde  = rand() % v.size();
       
       //wissel
       int hulp = v[begin];
       v[begin] = v[einde];
       v[einde] = hulp;
     }
}
