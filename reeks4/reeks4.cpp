#include "basics.h"
#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> &een,const int start,const int aantal);
void mergeSort(vector<int> &v);

int main(){
  const int AANTAL = 16;
  
  vector<int> v;
  vector<int> r;
  
  for (int i = 0 ; i < AANTAL ; i++){
    v.push_back(i);  
    }
  for (int i = 0 ; i < AANTAL ; i++){
    v.push_back(i);  
  }
  cout << "-------------------------------------before-------------------------------------" << endl << endl;
  cout << "v: " << endl;
  print(v);
  cout << endl << "een: " << endl;
  print(v,0,AANTAL);
  cout << endl << "twee: " << endl;
  print(v,AANTAL,2*AANTAL);
  
  cout << endl 
       << "-------------------------------------after--------------------------------------" << endl << endl;
  cout << endl << "result: " << endl;
  print(merge(v,0,AANTAL));
  mergeSort(v);
  print(v);
  
  cin.get();
}

vector<int> merge(vector<int> &v,const int start,const int aantal){
  int index1 = start;
  int index2 = start+aantal;
  int indexR = 0;
  
  vector<int> result(start+2*aantal);
  
  while (index1 < start+aantal){
    while (index2 < start+2*aantal && v[index2] <= v[index1]){
      result[indexR] = v[index2];//volgende insteken
      indexR++;
      
      index2++;//opschuiven
      }
    //index een insteken
    result[indexR] = v[index1];
    indexR++;
    
    index1++;
    }
  //overige van 2e tabel insteken
  while (index2 < start+2*aantal){
    result[indexR] = v[index2];
    indexR++;
    index2++;
  }
  
  return result;
}

void mergeSort(vector<int> &v){
  int aantal= 1;
  
  while (aantal < v.size()){
    cout << "aantal: " << aantal << endl;
    
    for (int i = 0 ; i<v.size() ; i+= aantal){
      cout << "i: " << i << "\tSize: " << v.size() << endl;
      v = merge(v,i,aantal);

    }
    
    aantal*=2;
  }
}
