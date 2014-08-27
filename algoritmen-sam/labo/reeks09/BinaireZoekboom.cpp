#include <iostream>
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
      //
      void voegtoe(const T &d);
      bool bevat(const T &d);
      int hoogte() const;
      void print() const;
      void maak_evenwichtig();
      void maak_evenwichtig(vector<T> &data, int links, int rechts);
      void walk( vector<T> &data);
   private:
      Zoekknoop<T>* k; // Ledige boom: nullpointer 
};


template <typename T>
Zoekboom<T>::Zoekboom(){
	k = 0;
}

template <typename T>
Zoekboom<T>::~Zoekboom(){
	delete k;
}

template <typename T>
void Zoekboom<T>::voegtoe(const T &d){
	Zoekknoop<T>* knoop = new Zoekknoop<T>(d);
	Zoekknoop<T>** loop = &k;
	
	while ( *loop != 0){
		if ( d < (*loop) -> data ){
			loop = &((*loop) -> links.k);
			
		}
		else{
			loop = &((*loop) -> rechts.k);
		}
	}
	*loop = knoop;	
}

template <typename T>
bool Zoekboom<T>::bevat(const T &d){
	Zoekknoop<T>** loop = &k;
	
	while ( *loop != 0 && (*loop) -> data != d){
		if ( d < (*loop) -> data ){
			loop = &((*loop) -> links.k);
			
		}
		else{
			loop = &((*loop) -> rechts.k);
		}
	}

	
	return (*loop) != 0;
}

template <typename T>
int Zoekboom<T>::hoogte() const{
	int hoogte;
	
	if ( k != 0){
		int h1 = k -> links.hoogte() + 1 ;
		int h2 = k -> rechts.hoogte() +1 ;
		hoogte = (h1 > h2 ? h1 : h2);
	}
	else{
		hoogte = 0;
	}
	return hoogte;
		
}

template <typename T>
void Zoekboom<T>::print() const{
	if (k != 0){
		k -> print();
	}		
}

template <typename T>
void Zoekboom<T>::maak_evenwichtig(){
		vector<T> data;
		walk(data);	
		delete k;
		k = 0;
		maak_evenwichtig(data, 0, data.size()-1);
}

template <typename T>
void Zoekboom<T>::maak_evenwichtig(vector<T> &data, int links, int rechts){
		if (links <= rechts){
			int midden = links + (rechts - links) /2;
			
			voegtoe(data[midden]);
			
			maak_evenwichtig(data, links, midden-1);
			maak_evenwichtig(data, midden+1, rechts);
		}
}

template <typename T>
void Zoekboom<T>::walk( vector<T> &structuur){
	if (k -> links.k != 0){
		k -> links.walk(structuur);
	}
	structuur.push_back(k -> data);
	if (k -> rechts.k != 0){
		k -> rechts.walk(structuur);	
	}
}
// Zoekknoop

template <typename T>
class Zoekknoop{
   friend class Zoekboom<T>;
   public:
      Zoekknoop(const T &d = T());
      void print();
   private:
      T data;
      Zoekboom<T> links, rechts;
};

template <typename T>
Zoekknoop<T>::Zoekknoop(const T &d){
		data = d;
}

template <typename T>
void Zoekknoop<T>::print(){		
		links.print();
		cout << data << " ";
		rechts.print();		
}




} // namespace BinaireZoekboom

