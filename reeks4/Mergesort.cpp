#include <iostream>
#include <iomanip>
#include <vector>
#include "Sorteermethode.cpp"
#include <ctime> 
#include "chrono.h"


using namespace std;

/* Class Sorteermethode */
template <typename T>
class Mergesort:public Sorteermethode<T>{
	public:
		void operator() (vector<T> &v) const{
			vector<T> h(v.size()/2);
			mergesort(v,0,v.size()-1,h);
		}
		void mergesort(vector<T> &v,int l,int r,vector<T> &h) const{
			if(l<r){
				int m=l+(r-l)/2;
				mergesort(v,l,m,h);
				mergesort(v,m+1,r,h);
				merge(v,l,m,r,h);
			}
		}
		void merge(vector<T> &v, int l, int m, int r, vector<T> &h) const{
   			//rechtse helft kopieren naar hulptabel
   			for(int i=0 ; i < (r-m) ; i++) {
      			h[i] = v[i+m+1];    
   			}
 
   			int il = m; //iterator die van het midden naar het begin van de tabel zal lopen
   			int ih = r-m - 1; //iterator die van einde van de hulptabel naar begin van de hulptabel zal lopen
 
   			int i = 0; 
 
   			while(il >= l && ih >= 0) { //zolang beide iteratoren nt te klein worden
      			if(v[il] < h[ih]) { //element van hulptabel is groter dan die van tabel, dus moet die van hulptabel achteraan in de tabel komen
         			v[r-i]=h[ih];
         			ih--;
      			}
      			else { //element van tabel is groter dan die van hulptabel, dus moet die van tabel achteraan in de tabel komen
					v[r-i]=v[il];
					il--;
      			}
      			i++;
   			}
   			//nu controleren we of we de hulptabel al helemaal overlopen hebben, zonee, dan kopieren we de rest naar de tabel.
			while(ih>=0){
				v[r-i]=h[ih];
				i++;
				ih--;
			}
		}
};
