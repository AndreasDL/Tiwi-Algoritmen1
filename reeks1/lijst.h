//Implementeer de lidfunctie zoek_gerangschikt(d) die de plaats zoekt waar d staat of zou 
//moeten staan in een stijgend gerangschikte lijst.
// Implementeer de lidfunctie insertion_sort() die de lijst stijgend rangschikt, uiteraard met insertion sort. 
// Let wel: de knopen mogen enkel verplaatst worden. 
// Aanmaken van nieuwe knopen, en knopen verwijderen, is inefficiënt en dus verboden. 
// Ook niet toegelaten is het gebruik van STL-containers (en zeker std::list), of C-tabellen. 

namespace Lijsten{ 
// Lijst 

template class Lijstknoop; 

template class Lijst{ 
  public: 
    Lijst(); 
    Lijst(const Lijst &l); 
    ~Lijst(); 
    // 
    Lijst& Lijst::operator=(const Lijst &l); 
    void voeg_toe_vooraan(const T &d); 
    void insertion_sort();
    Lijst* zoek_gerangschikt(const T &d);
  private: 
    Lijstknoop* k; 
}; 
                  
template 
Lijst::Lijst(){ 
  k=0; 
} 
                  
template 
Lijst::Lijst(const Lijst &l){
  Lijst* p = this; 
  Lijstknoop* q = l.k; 
  while(q != 0){ 
    p->k = new Lijstknoop(q->data); 
    p = &(p->k->opv); q = q->opv.k; 
  } 
} 

template 
Lijst::~Lijst(){ 
  delete k; 
} 

template 
Lijst& Lijst::operator=(const Lijst &l){ 
  if(this != &l){ 
    delete k; 
    Lijst* p = this; 
    Lijstknoop* q = l.k; 
    while(q != 0){ 
           p->k = new Lijstknoop(q->data); 
           p = &(p->k->opv); 
           q = q->opv.k; 
    } 
  } 
  return *this; 
} 

template 
void Lijst::voeg_toe_vooraan(const T &d){ 
  Lijstknoop* h=k; 
  k = new Lijstknoop(d); 
  k->opv.k = h; 
}



template 
void Lijst::insertion_sort(){
         
}



// Lijstknoop 

template 
class Lijstknoop{ 
  friend class Lijst; 
  public: 
          Lijstknoop(const T &d = T()); 
  private: 
           T data; 
           Lijst opv; 
}; 

template 
Lijstknoop::Lijstknoop(const T &d) : data(d) {}

} // namespace Lijsten 
