#include <vector>
using namespace std;

namespace BinaireZoekboom{
  
  // Zoekboom
  
  template <typename T>
  class Zoekknoop;
  
  template <typename T>
  class Zoekboom{
     public:
        Zoekboom();
        ~Zoekboom();
        void maak_evenwichtig();
        void voegtoe(const T &d);
        bool bevat(const T &d) const;
        int hoogte() const;
     private:
        Zoekknoop<T>* k; // Ledige boom: nullpointer 
        void steekInVector(vector<T> &v);
  };
  
  template<typename T>
  void Zoekboom<T>::maak_evenwichtig(){
    vector<T> v;
    //inorder in vector steken
    steekInVector(v);
    //controle
    for (int i = 0 ; i < v.size() ; i++){
      cout << v[i] << endl;
      }
      
    //heropbouwen
    Zoekboom* b = new Zoekboom();
    
    //als root zetten
    b->k->data = v[i];
    
    //recursief 
    
  }
  
  template<typename T>
  void Zoekboom<T>::steekInVector(vector<T> &v){
    if (this->k != 0){
        if(this->k->links.k != 0){
          steekInVector(v);
        }
   
        v.push_back(k->data);
   
        if(this->k->links.k != 0){
          steekInVector(v);
        }
  }
  
  template<typename T>
  void Zoekboom<T>::heropbouw(vector<T> &v,int start,int stop,Zoekknoop<T>* knoop){
    //mediaan nemen
    int i = (stop-start) /2;
    if (i > 1) {
      knoop->data = v[i];
      
      heropbouw(v,start,start+i,knoop->links->k);
      heropbouw(v,start+i,stop,knoop->rechts->k);
    } else if (i == 1) { //i==1 => 1 kind
      knoop->data = v[i];
    } else {//i == 0 => geen kindere
      knoop->links = 0;
      knoop->rechts = 0;
    }
    
  }
            
    
    return v;
  }
  
  // Zoekknoop
  
  template <typename T>
  class Zoekknoop{
     friend class Zoekboom<T>;
     public:
        Zoekknoop(const T &d = T());
     private:
        T data;
        Zoekboom<T> links, rechts;
  };
  
} // namespace BinaireZoekboom
