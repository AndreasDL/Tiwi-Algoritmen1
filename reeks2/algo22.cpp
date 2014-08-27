#include <iostream>
#include <map>
#include <vector>
#include <stdlib.h>
#include "chrono.h"
using namespace std;

void fillVector(const int aantal, vector<int> &v,int min, int max);
void print(const vector<int> &v);
void preSort(vector<int> &v,const int a);
void insertionSort(vector<int> &v);
void copyVector(const vector<int> &in,vector<int> &uit);
void shuffleVector(vector<int> &v);

int main(){
    const int AANTALIT = 25;
    const int VSIZE = 10000;
    const int MINVAL = 0;
    const int MAXVAL = 1000;
    const int A = 10;
    
    //setup
    vector<int> v;
    fillVector(VSIZE,v,MINVAL,MAXVAL);
      
    for (int i = 0 ; i < AANTALIT ; i++){      
      Chrono c;
      cout << "round: " << i+1 << "\t";
      
      //algoritm v1
      vector<int> w;
      copyVector(v,w);
      c.start();
      std::sort(w.begin(),w.end());   
      c.stop();
      double m1Tijd = c.tijd();
      cout << "m1: " << m1Tijd << "\t";
      
      //algoritm v2
      copyVector(v,w);
      c.start();
      insertionSort(w);
      c.stop();
      double m2Tijd = c.tijd();
      cout << "m2: " << m2Tijd << "\t";
      
      //algoritme v3
      copyVector(v,w);
      c.start();
      preSort(w,A);
      insertionSort(w);
      c.stop();
      double m3Tijd = c.tijd();
      cout << "m3: " << m3Tijd << "\t";
      
      cout << "totaal: " << m1Tijd + m2Tijd + m3Tijd << endl;
      
      shuffleVector(v);
    }
    
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
      while (i < v.size() && v[i] < v[i]+1){
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
