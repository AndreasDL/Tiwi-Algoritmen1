#ifndef sorteerTijd
#define sorteerTijd
#include<vector>
#include "sortMethod.h"
#include "chrono.h"
using namespace std;

double sorteerTijd(const vector<int> &v, const SortMethod &sort, int ncycli=1){
  cout << "hoi";
  Chrono c;
  vector<double> tijden(ncycli);
  
  vector<int> temp(v.size());
  for (int i = 0 ; i < v.size() ; i++){
    temp.push_back(v[i]);
  }
  
  for (int i = 0 ; i < ncycli ; i ++){
    c.start();
    sort(temp);
    c.stop();
    tijden.push_back(c.tijd());
    
    //originele herstellen
    vector<int> temp(v.size());
    for (int i = 0 ; i < v.size() ; i++){
      temp.push_back(v[i]);
    }
  }
  double som = 0;
  if (ncycli >= 3){
    //min en max vinden
    std::sort(tijden.begin(), tijden.end());
    for (int i = 1 ; i < tijden.size() - 1  ; i++){
      som+= tijden[i];
    }
    
    return som/(ncycli-2);
  }else{
    for (int i = 0 ; i < tijden.size() ; i++){
      som+=tijden[i];
      }
    return som/ncycli;
  }
}

#endif
