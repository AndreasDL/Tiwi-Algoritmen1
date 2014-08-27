#include <iostream>
using namespace std;

namespace Lijsten{

// Lijst

template <typename T>
class Lijstknoop;

template <typename T>
class Lijst{
   public:
      Lijst();
      Lijst(const Lijst &l);
      ~Lijst();
      //
      Lijst<T>& operator=(const Lijst<T> &l);
      void voeg_toe_vooraan(const T &d);
      void insertion_sort();
      Lijstknoop<T>* zoek_gerangschikt(const T &d);
   private:
      Lijstknoop<T>* k;
};

template <typename T>
Lijst<T>::Lijst(){
   k=0;
}

template <typename T>
Lijst<T>::Lijst(const Lijst &l){
   Lijst* p = this;
   Lijstknoop<T>* q = l.k;
   while(q != 0){
      p->k = new Lijstknoop<T>(q->data);
      p = &(p->k->opv);
      q = q->opv.k;
   }
}

template <typename T>
Lijst<T>::~Lijst(){
   delete k;
}

template <typename T>
Lijst<T>& Lijst<T>::operator=(const Lijst<T> &l){
   if(this != &l){
      delete k;
      Lijst* p = this;
      Lijstknoop<T>* q = l.k;
      while(q != 0){
         p->k = new Lijstknoop<T>(q->data);
         p = &(p->k->opv);
         q = q->opv.k;
      }          
   }
   return *this;
}

template <typename T>
void Lijst<T>::voeg_toe_vooraan(const T &d){
   Lijstknoop<T>* h=k;
   k = new Lijstknoop<T>(d);
   k->opv.k = h;
}

void insertion_sort(){
     
}

template <typename T>
Lijstknoop<T>* Lijst<T>::zoek_gerangschikt(const T &d){
    Lijstknoop<T>* knoop = this->k;
    while ( knoop -> data != 0 && knoop->data < d->data ){
          knoop = knoop->opv;
    }
    
    return knoop;
}

   
// Lijstknoop

template <typename T>
class Lijstknoop{
   friend class Lijst<T>;
   public:
      Lijstknoop(const T &d = T());
   private:
      T data;
      Lijst<T> opv;
};

template <typename T>
Lijstknoop<T>::Lijstknoop(const T &d) : data(d) {}




int main(){
    cout << "hoi" << endl;
    
    Lijst<int> l = new Lijst();
    
    for (int i = 9 ; i > 0 ; i-){
        l.voeg_toe_vooraan(i);
        cout << i << endl;   
    }
    
cin.get();
return 0;    
}

} // namespace Lijsten
