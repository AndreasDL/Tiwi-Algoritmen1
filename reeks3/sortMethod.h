#ifndef sortMeth
#define sortMeth

#include<vector>
using namespace std;

class SortMethod{
  public : 
    virtual void operator()(vector<int> &v)const =0;
};

class InsertionSort : public SortMethod{
  public :
    void operator()(vector<int> &v)const {
        for(int i=1; i<v.size(); i++){
          // de i eerste elementen staan reeds in volgorde
          int hulp = v[i]; // we halen het i-de element er uit.
          int j=i-1;
          while(j>=0 && hulp<v[j]){
                  // alle elementen groter dan het i-de element worden 1 plaats naar rechts opgeschoven
                  v[j+1] = v[j];
                  j--;
          }
          v[j+1] = hulp; // we voegen het uitgehaalde in op zijn juiste plaats.
        }
    }
};
class ShellSort : public SortMethod{
  public : 
    void operator()(vector<int> &v)const {
      //waarden maken
      vector<int> waarden;
      int hulp = v.size()/2;
      while(hulp > 0){
        waarden.push_back(hulp);
        hulp=hulp/2;
      }
        
      for (int i = 0 ; i < waarden.size() ; i++){
        preSort(v,waarden[i]);
      //  cout << "progress: " << waarden[i] << endl;
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

class HeapSort : public SortMethod{
  public : 
    void operator()(vector<int> &v)const {
      
      cout << "voor" << endl;
      for (int i = 0 ; i < v.size() ; i++){
        cout << v[i] << endl;
      }
      
      construeer_heap(v);
      
      cout << "na" << endl;
      for (int i = 0 ; i < v.size() ; i++){
        cout << v[i] << endl;
      }
    }
  private : 
    void construeer_heap(vector<int> &v)const {
      //waarden maken
      for (int i = 1 ; i <= v.size() ; i++){
        int j = i;
        
        while ( j>1 && v[j-1] > v[j/2-1]){ //zolang kind groter is dan ouder => omwisselen van kind en ouder.
        //swap als kind groter is dan ouder
          int hulp = v[j-1];
          v[j-1] = v[j/2-1];
          v[j/2-1] = hulp;
          j /=2;
          //v[j-1] = huidige bol
          //v[j/2-1] = huidige ouder
          //j/=2 => volgende ouder
        }
      }
    }
};
#endif
