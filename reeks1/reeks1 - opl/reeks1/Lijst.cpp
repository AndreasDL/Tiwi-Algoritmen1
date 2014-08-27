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
	  Lijst<T>* zoek_gerangschikt(const T &d);
	  T getFirstValue();
	  void toon_elementen();
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
Lijst<T>* Lijst<T>::zoek_gerangschikt(const T &d){
	Lijst<T>* h = this;
	while (h->k != 0 && h->k->data < d) {
		h = &(h->k->opv);
	}
	return h;
}

template <typename T>
void Lijst<T>::insertion_sort(){
	Lijstknoop<T> *huidig = k;
    while ( huidig != 0 ){
		Lijstknoop<T>* opvolger = huidig->opv.k;
		if (opvolger != 0 && opvolger->data < huidig->data){
			
			Lijstknoop<T>** knoop = &k;
			while ((*knoop)->data < opvolger->data){
				knoop = &((*knoop)->opv.k);
			}
			Lijstknoop<T>* temp = *knoop;
			huidig->opv.k = opvolger->opv.k;
			*knoop = opvolger;
			opvolger->opv.k = temp;
			
		}
		huidig = opvolger;
     }
}

template <typename T>
void Lijst<T>::toon_elementen(){
	Lijstknoop<T> *i = k;
	while (i != 0){
		cout << i->data << endl;
		i = i->opv.k;
	}
	cout << endl;
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

} // namespace Lijsten
