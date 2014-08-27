#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;
vector<map<long,vector<string> > > prepData(ifstream &in);
long getValue(const string &line);

int main(){
  ifstream in;
  in.open("woorden.txt");
  cout << "reading input" << endl;
  vector<map< long,vector<string> > > data = prepData(in);
  cout << "reading done";
  in.close();
  
  ifstream inn;
  inn.open("bepaal_anagrammen_van.txt");
  string line;
  while (inn.is_open() && !inn.eof()){

    getline(inn,line);
    cout << "zoek : " << line << endl;
    
    vector<string> opl = data[line.size()-3][getValue(line)];
    for (int i = 0 ; i < opl.size() ; i++){
      cout << opl[i] << endl;
      }
    cout << endl;
  }
  inn.close();  
  
  cout << "druk op een toets om verder te gaan" << endl;
  cin.get();  
}

vector<map<long,vector<string> > > prepData(ifstream &in){
    vector<map<long,vector<string> > > data(10);

    string line;

    while ( in.is_open() && !in.eof()){
      getline(in,line);
      
      if( line.size() <= 12 && line.size() >= 3){//woorden die je zoekt zijn niet langer dan 12 en niet korter dan 3
        data[line.size()-3][getValue(line)].push_back(line);
        //cout << line << line.size() << " " << getValue(line) <<endl;
      }      
    }
      
    return data;
}

long getValue(const string &line){
  long value = 1;
    for (int i = 0 ; i < line.size() ; i++){
          value *= line[i];
   }
  return value;
  }
