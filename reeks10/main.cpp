#include <fstream>
#include "graaf.h"
using namespace std;

template <GraafType TYPE>
vector<int> segmentPerKnoop(const Graaf<TYPE> &g);


int main(){
  Graaf<ONGERICHT> g;
  ifstream in("input.txt");
  g.lees(in);
  
  cout << g;
  
  vector<int> v = segmentPerKnoop(g);
  cout << "vsize : " << v.size() << endl;
  for (int i = 0 ; i < v.size() ; i++){
    //cout << "i:" << i << " behoort tot : " << v[i] << endl;  
  }
  cin.get();
  return 0;
}

template <GraafType TYPE>
vector<int> segmentPerKnoop(const Graaf<TYPE> &g){
  
  vector<int> v(g.aantal_knopen());
  for (int i = 0 ; i < g.aantal_knopen() ; i++){
    v[i] = -1;  
  }//-1 => behoort niet tot een segment
  
  int segNr = -1;
  
  for (int i = 0 ; i < v.size();i++){//alle knopen overlopen
  cout << i << endl;
    //indien de knoop nog niet tot segment behoort => nieuw segment
    if (v[i] == -1){
      segNr++;
    }
    
    //segment geveven aan de knoop
     v[i] = segNr;
     
    //alle buren => zelfde segment
    for (map<int,int>::const_iterator it = g[i].begin(); it != g[i].end() ; it++){
      cout << "\t" << it->first << " segnr: " << segNr << endl;
      v[it->first] = segNr;
      }
    
    //alle buren => zelfde segment nummer;
    }  
}
