#ifndef BASICS
#define BASICS
#include <vector>
#include <stdlib.h>
#include <iostream>
using namespace std;

void fillVector(const int aantal, vector<int> &v,int min, int max);
void print(const vector<int> &v);
void preSort(vector<int> &v,const int a);
void insertionSort(vector<int> &v);
void copyVector(const vector<int> &in,vector<int> &uit);
void shuffleVector(vector<int> &v);
void fillVectors(const int aantal,const int max, const int min,vector<int> &sorted,vector<int> &scrambled,vector<int> &reverse);

void fillVectors(const int aantal,const int max, const int min,vector<int> &sorted,vector<int> &scrambled,vector<int> &reverse){
  int hulp = max-min+1;
  sorted.clear();
  scrambled.clear();
  reverse.clear();
  
  //maak 3 keer een random
  for (int i = 0 ; i < aantal ; i++){
    int temp = rand()%hulp+min;
      sorted[i] = temp;
      scrambled[i] = temp;
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
    reverse[sorted.size()-1-i] = sorted[i];
  }
}

void fillVector(const int aantal, vector<int> &v, int min , int max){
  int h  = max - min + 1;
  for (int i = 0 ; i < aantal ; i++){
      v[i] = (rand()|rand() << 16)%h + min; // 32 bit random generator :)
  }
}

void print(const vector<int> &v){
     for (int i = 0 ; i < v.size() ; i++){
          cout << v[i] << "\t";
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
void print(const vector<int> &v,const int start, const int stop){
  if (stop <= v.size() && start >= 0 ){
    for (int i = start ; i < stop ; i++){
      cout << v[i] << "\t";
      }
    }
  
  }
#endif
