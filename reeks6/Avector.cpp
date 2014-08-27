#ifndef AVECTOR
#define AVECTOR
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Avector : public vector<T>{
  private:
    vector<T> een;
    vector<T> twee;
  public:
    //constructor
    Avector<T>(): vector<T>(){};
    //poppers
    void pop_front();
    void pop_back();
    //pushers
    void push_front(const T &t);
    void push_back(const T &t);
    int size() const;
    //operators
    const T& operator[](const int nIndex)const ;//const ref terug geven voor grote dingen
    //terug geven van een waarde op een bepaalde index const moet er staan zodat compiler weet welkeen hij nodig heeft.
    T& operator[](const int i);//waarde zetten op bepaalde index
    //debugging
    void print()const;
};

template <typename T>
void Avector<T>::print()const {//debugging only
  cout << "printlst: total size: " << size() << "\neen: size: " << een.size() << endl;
  for (int i = een.size()-1 ; i >= 0 ;i--){
    cout << "i: " << i << " val: " << een[i] << endl;
  }
  
  cout << "twee: size: " << twee.size() << endl;
  for (int i = 0; i < twee.size() ; i++){
    cout << "i: " << i << " val: " << twee[i] << endl;
  }
  
  cout << "done" << endl << endl;
}

template <typename T>
void Avector<T>::push_back(const T &t){
  twee.push_back(t);  
}

template <typename T>
void Avector<T>::push_front(const T &t){
  een.push_back(t);  
}

template <typename T>
int Avector<T>::size()const{
  return een.size() + twee.size();
}

template <typename T>
void Avector<T>::pop_front(){
  if (size() > 0){
    if (een.size() > 0){
      een.pop_back();
    }else if (twee.size() > 0){
      //alles opschuiven + versteken indien mogelijk
      
    }
  }
}

template <typename T>
void Avector<T>::pop_back(){
  if (size() > 0 ){
    if (twee.size() > 0 ){
      twee.pop_back();
    }else if (een.size() > 0){
        
    }
  }  
}
#endif
