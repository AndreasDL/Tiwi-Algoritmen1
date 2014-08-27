#include <iostream>
#include <vector>
#include "Avector.cpp"
using namespace std;

int main(){
  Avector<int> av;
  
  av.push_back(10);
  av.push_back(10);
  av.push_back(145131);
  av.push_back(1541);
  av.push_back(15);
  
  av.push_front(22);
  av.push_front(25);
  av.push_front(28);
  
  cout << "init done" << endl;
  av.print();
  
  cout << "pop_front()" << endl;
  av.pop_front();
  av.print();
  
  cout << "pop_back()" << endl;
  av.pop_back();
  av.print();
  
  cout << "push_front()" << endl;
  av.push_front(30);
  av.print();
  
  cout << "push_back()" << endl;
  av.push_back(40);
  av.print();
    
  cin.get();  
}
