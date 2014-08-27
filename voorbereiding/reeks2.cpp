#include <iostream>
#include <vector>
#include "sortMethod.h"
using namespace std;

int main(){
  const int AANTAL = 10000;
  
  vector<int> v(AANTAL);
  for (int i = 0 ; i < AANTAL; i++){
    v[i] = rand();
  }
  
  for (int i = 0 ; i < AANTAL ; i++){
    cout << v[i] << "\t";  
  }
  
  //mode bepalen
  //min en max
  int min = v[0];
  int max = v[0];
  for (int i = 0 ; i < v.size() ; i++){
    if (v[i] < min ){
      min = v[i];
    }else if( v[i] > max){
      max = v[i];  
    }
  }
  
  //mode zelf
  vector<int> mode(max-min+1);
  for (int i = 0 ; i < v.size() ; i++){
      mode[v[i]-min]++;
  }
  cin.get();
  
  int max=0;
  for (int i = 0 ; i < mode.size() ; i++){
    if (mode[max] > mode[i]){
      max = i;  
    }
  }
  cout << "de mode is : " << mode[max] << endl;
}
