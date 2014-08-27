#include <iostream>
#include "Sorteermethode.cpp"
#include "Insertionsort.cpp"

using namespace std;

template <typename T>
class Shellsort:public Sorteermethode<T>{
	public:
		void operator() (vector<T> &v) const{
			int teller=0;
			int k=(int)volgendeK(teller++);

			while (k>1){
				for (int i=k; i<v.size(); i++){
					//vorige getallen staan al in volgorde
					T h = v[i];
					int j = i-k;
					while (j>= 0 && h< v[j]){
						v[j+k]=v[j];
						j-=k;
					}
					v[j+k] = h;
				}
				k=(int)volgendeK(teller++);
			}
			Insertionsort<T> i;
			i(v);
		}
		private:
			double volgendeK(int i) const{
				int tabel[] = {1,3,7,14,28,57,115,230,460,921,1843,3686,7372,14745,29491,58982,117964,235929,471859,943718};
				return tabel[20-i];
			}
};

