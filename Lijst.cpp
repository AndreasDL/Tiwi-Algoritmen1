#include <iostream>
using namespace std;

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
      Lijst<T>& Lijst<T>::operator=(const Lijst<T> &l);
      void voeg_toe_vooraan(const T &d);
      void insertion_sort();
	  Lijst<T>* zoek_gerangschikt(const T &d);
	  //debugging
	  void print() const; //debugging
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

template <typename T>
void Lijst<T>::insertion_sort(){

	while (pList != NULL){
      Lijst<T>* pHead = this; /* remember the head */
      Lijst<T>** ppTrail = &pSorted; /* trailing pointer for efficient splice */
 
      /* pop head off list */
      pList = pList->pNext;
 
      /* splice head into sorted list at proper place */
      while (TRUE)
        {
          /* does head belong here? */
          if (*ppTrail == NULL || pHead->iValue < (*ppTrail)->iValue)
            {
              /* yes */
              pHead->pNext = *ppTrail;
              *ppTrail = pHead;
              break;
            }
          else
            {
              /* no - continue down the list */
              ppTrail = & (*ppTrail)->pNext;
            }
        }
    }

}

template <typename T>
Lijst<T>* Lijst<T>::zoek_gerangschikt(const T &d){
	Lijst<T>* it = this;

	while (it->k != 0 && it->k->data < d ){
		it = &(it->k->opv);
	}
	
	//cout << d << " moet komen voor " << it->k->data << endl;
	return it;
}

template <typename T>
void Lijst<T>::print() const{

	const Lijst<T>* lijst = this;

	while (lijst->k != 0){
		cout << lijst->k->data << endl;
		lijst = &(lijst->k->opv);
	}
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

	//debugging
	Lijst<int>* lijstje = new Lijst<int>();
	
	//lijstje->voeg_toe_vooraan(685857279);
	//lijstje->voeg_toe_vooraan(87829);
	//lijstje->voeg_toe_vooraan(8889);
	//lijstje->voeg_toe_vooraan(789);
	//lijstje->voeg_toe_vooraan(59);
	lijstje->voeg_toe_vooraan(7);
	lijstje->voeg_toe_vooraan(9);
	lijstje->voeg_toe_vooraan(5);
	lijstje->voeg_toe_vooraan(4);
	lijstje->voeg_toe_vooraan(2);
	lijstje->voeg_toe_vooraan(1);

	cout << "starten met :" << endl;
	lijstje->print();

	//Lijst<int>* punt = lijstje->zoek_gerangschikt(7);

	lijstje->insertion_sort();



	cin.get();
	return 0;
}