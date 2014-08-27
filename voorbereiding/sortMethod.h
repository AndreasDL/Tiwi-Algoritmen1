#include <iostream>
#include <vector>
using namespace std;

#ifndef FUNCTOR
#define FUNCTOR

template <typename T>
class SortMethod{
  public:
    virtual void operator()(vector<T> &v) const=0;
};

template <typename T>
class InsertionSort:public SortMethod<T>{
  public : 
  virtual void operator()(vector<T> &v)const {
    for (int i = 1 ; i < v.size() ; i++){
      //pak element
      int hulp = i-1;
      T el = v[i];
      while (hulp >=0 && el < v[hulp]){
        v[hulp+1] = v[hulp];
        hulp--;
        }
      //steek ertussen
      v[hulp+1] = el;
      }  
  }
};

template <typename T>
class ShellSort:public SortMethod<T>{
  public : 
    virtual void operator()(vector<T> &v)const{
      vector<int> a;
      
      int hulp = v.size();
      while (hulp > 1){
        a.push_back(hulp);
        hulp/=2;
        }
      for (int i = 0 ; i < a.size() ; i++){
        preSort(v,a);  
      }
    }
  private :
    void preSort(vector<int> &v,const int a)const {
      for(int i=1; i<v.size(); i++){
      // de i eerste elementen staan reeds in volgorde
        int hulp = v[i]; // we halen het i-de element er uit.
        int j=i-a;
        while(j>=0 && hulp<v[j]){
          // alle elementen groter dan het i-de element worden 1 plaats naar rechts opgeschoven
          v[j+a] = v[j];
          j-=a;
        }
        v[j+a] = hulp; // we voegen het uitgehaalde in op zijn juiste plaats.
      }     
    }
};


#endif
