#include <iostream>
#include <vector>
#include "chrono.h"
using namespace std;

vector<int> getVector(const int min, const int max, const int aantal);
void print(const vector<int> &v);

int main(){
  const int AANTAL = 10000;
  const int MIN=1000;
  const int MAX=2000;
  int doel = 408094;
  
  //fill
  vector<int> v = getVector(MIN,MAX,AANTAL);
  sort(v.begin(),v.end());//,std::greater<int>());

  cout << "Zoeken naar doel " << doel << " in tabel: " << endl;
  print(v);
  Chrono c;
  c.start();
  int bruikbareSize = v.size();//alles wat groter is dan het doel mag eigenlijk weg.
  int som = 0;
  int grootsteKleiner = 0; //index
  int beginDoel = doel;//begindoel bijhouden
  vector<int> verzameling; //gevonden getallen bijhouden.
  int iteratie =0;
  
  while (bruikbareSize > 0 && som != beginDoel){
    
    //zoek grootste getal net kleiner is
    for (int i = 0 ; i < bruikbareSize ; i++){
      if (doel - v[i] <= doel-v[grootsteKleiner] && doel-v[i] >= 0){
        grootsteKleiner = i;
      }
    }
    
    if (grootsteKleiner == 0 && som != beginDoel){
      cout << "next iteratie it: " << iteratie << endl;
      iteratie++;
      //cleanup
      verzameling.clear();
      som = 0;
      doel = beginDoel;
      //zoeken vanaf een kleiner
      bruikbareSize = v.size() - iteratie;
    }else{
      som += v[grootsteKleiner];
      doel -= v[grootsteKleiner];
      bruikbareSize = grootsteKleiner;
      verzameling.push_back(v[grootsteKleiner]);
      
      cout << "\t"
           << "grootste kleiner: " << v[grootsteKleiner] 
           << " op: " << grootsteKleiner 
           << " (=bruikSize) som: " << som
           << " nodig: " << doel 
           << endl;
    }
    
    grootsteKleiner = 0;
  }

  //zoek nieuw grootsteKleiner maar nu kleiner dan het verschil
  if (som == beginDoel){
    c.stop();
    cout << "gevonden!!"
         << " doel: " << beginDoel 
         << " aantalGetallen: " << verzameling.size() 
         << " aantalIteraties: " << iteratie+1 
         << " tijd: " << c.tijd()
         << endl;
         
    for (int i = 0 ; i < verzameling.size() ; i ++){
      cout << verzameling[i] << "\t";
    }
  }else{
    c.stop();
    cout << endl 
         << "doel: " << beginDoel 
         << " niet gevonden!!"
         << " verlorenTijd: " << c.tijd() 
         << endl;
  }
  cin.get();
  return 0;  
}

vector<int> getVector(const int min, const int max, const int aantal){
  vector<int> v(aantal);
  int hulp = max-min+1;
  for (int i = 0 ; i < aantal ; i++){
    v[i] = min+(rand()%hulp);
  }
  
  return v;
}
void print(const vector<int> &v){
  for (int i = 0; i < v.size() ; i++){
    cout << v[i] << "\t";
    }
}
