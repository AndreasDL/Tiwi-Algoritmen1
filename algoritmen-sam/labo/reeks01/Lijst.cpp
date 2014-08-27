#include <iostream>
using namespace std;


namespace Lijsten {
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
      void merge_sort();
      void schrijf_uit();
      Lijstknoop<T>* zoek_gerangschikt(T d);
   private:
      Lijstknoop<T>* k;
      void merge(Lijst<T>* start, Lijst<T>* midden, Lijst<T>* stop);
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

template <typename T>
Lijstknoop<T>* Lijst<T>::zoek_gerangschikt(T d){
   Lijstknoop<T>* loop = k;
   while (loop != 0 && loop -> data < d){
	   loop = loop -> opv.k;
   }
   return loop;
}

template <typename T>
void Lijst<T>::insertion_sort(){
    Lijstknoop<T> *huidig = k;
    while ( huidig != 0 ){
		Lijstknoop<T> *opvolger = huidig -> opv.k;
		if (opvolger != 0 && opvolger -> data < huidig -> data){
			
			Lijstknoop<T>** loop = &k;
			while ( (*loop) -> data < opvolger -> data){
				loop = &( (*loop) -> opv.k);
			}
			Lijstknoop<T>* temp = (*loop);
			huidig -> opv.k = opvolger -> opv.k;
			(*loop) = opvolger;
			opvolger -> opv.k = temp;
			
		}
		huidig = opvolger;
     }
}

template <typename T>
void merge(Lijst<T>* start, Lijst<T>* midden, Lijst<T>* stop){
	
	
}
template <typename T>
void Lijst<T>::merge_sort(){
	
	
}

template <typename T>
void Lijst<T>::schrijf_uit(){
     Lijstknoop<T> *i = k;
     while ( i != 0 ){
           cout << i -> data << endl;
           i = i -> opv.k;
     }
}

}


