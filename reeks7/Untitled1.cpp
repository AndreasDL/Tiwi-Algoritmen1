#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void decodeFile( const string &file);
struct Knoop{
public:
  Knoop* kind1;
  Knoop* kind2;
  string value;
  int n;
  string toString()const {
    if (n == 2){
      return "(" + kind2->toString() + value + kind1->toString() + ")";
    }else if (n ==1){//kind2 is niet nul anders zou eerste test getriggerd worden.
      return "(" + kind1->toString() + ")";
    }else{
      return value;  
    } 
  }
  ~Knoop(){
    delete kind1;
    delete kind2;
    }
};
Knoop* decode(string &line);

int main(){
  decodeFile("formules_poolse_notatie.txt");
//  string start = "cab+*";
//  Knoop* oplossing = decode(start);
//  cin.get();
//  cout << oplossing->toString();
//  delete oplossing;
  
  cin.get();
  return 0;
  } 
  
  

Knoop* decode(string &line){
  Knoop* start = new Knoop();
  char c = line[line.size()-1];
  start->value = c;
  
  if (line.size() >0 ){
    line = line.substr(0,line.size()-1);
    if ( c == '+' || c == '-' || c == '*' || c == '/' || c == '%'){//2kinderen
        start->kind1 = decode(line);
        start->kind2 = decode(line);
        start->n = 2;
     }else if( c == '!' && c == '@' ){//maar een kind
        start->kind1 = decode(line);
        start->n = 1;
    }else{
      start->n = 0;
    }
  }
  return start;
}

  
void decodeFile(const string &file){
  ifstream in(file.c_str());
  string line;  
  while (!in.eof()){
    in >> line;
    Knoop* oplossing = decode(line);
    cout << oplossing->toString() << endl;
//  delete oplossing;
  }
  
}
