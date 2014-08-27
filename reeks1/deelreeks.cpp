#include <iostream>
#include <string>
using namespace std;

int main(){
  int aantal;
  cin >> aantal;
  
  vector<int> rij;
  for (int i = 0 ; i < aantal ; i ++){
    int hulp;
    cin >> hulp;
    rij.push_back(hulp);
    }
    
  int result;
  cin >> result;
  
  cout << aantal << " " << result << " "  << rij << endl;
  
  cin.get();
  return 0;
  }
