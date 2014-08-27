#include <iostream>
#include <vector>
#include "chrono.h"
using namespace std;

#ifndef BASICS
#define BASICS

template <typename T>
void print(const vector<T> &v){
  for (int i = 0 ; i < v.size() ; i++){
    cout << v[i] << "\t";
    }  
  cout << endl << endl;
}

void fillVector(const int aantal,const int min,const int max,vector<int> &v){ 
  int hulp = max-min+1;
  for (int i = 0 ; i < aantal ; i++){
      v[i] = min+rand()%hulp;
  }
}

template <typename T>
double sortTime(const vector<T> &v, const SortMethod<T> &sort, int ncycli=1){
  Chrono c;
  double totTijd = 0.0;
  
  for (int i = 0 ; i < ncycli ; i++){
    c.start();
    sort(v);
    c.stop();
    totTijd+=c.tijd();
  }
  
  
  return totTijd/ncycli; 
}
#endif
