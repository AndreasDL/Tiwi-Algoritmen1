#include <iostream>
#include <vector>
#include "sortMethod.h"
#include "basics.h"
using namespace std;

int main(){
  const int AANTAL = 100;
  const int MIN = 0;
  const int MAX = 1000;
  const int NCYCLI = 10;
  
  vector <int> v(AANTAL);
  fillVector(AANTAL,MIN,MAX,v);
  
  InsertionSort<int> ins;
  
  cout << sortTime(v,ins,NCYCLI);
  
  cin.get();
}
