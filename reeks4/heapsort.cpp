#include <iostream>
#include <iomanip>
#include <vector>
#include "Sorteermethode.cpp"
#include <ctime> 
#include "chrono.h"


using namespace std;

/* Class Sorteermethode */
template <typename T>
class Heapsort:public Sorteermethode<T>{
	public:
		void operator() (vector<T> &v) const{
			/*int n = v.size();
    		construeer_heap(v);	
    		for(int i = v.size() - 1 ; i > 0; i--){
                int temp = v[0];
                v[0] = v[i];
                v[i] = temp;
                fix_heap(v, i);
            }*/
            construeer_heap(v);
			for (int i = 1; i < v.size(); i++){
				swap(v[0], v[v.size()-i]);
				//nieuwe wortel zoeken
				int j = 0;
				while ( (2*j+1 < v.size()-i && v[j] < v[2*j+1]) || (2*j+2 < v.size()-i && v[j] < v[2*j+2]) ){
					int aant = aantal_kinderen(j, v.size()-i);
					int index = 0;
					if (aant == 2){
						index = (v[2*j+1] < v[2*j+2] ? 2*j+2 : 2*j+1);
					}
					else if (aant == 1){
						index = 2*j+1;
					}
					swap(v[j], v[index]);
					j = (index > j ? index : 2*j+1);
				}
			
			}
		}
		void construeer_heap(vector<T> &v) const{
			for (int i = 1; i < v.size(); i++){
				int huidig = i;
				int ouder = (i - 1) / 2;
				while (huidig > 0 && v[ouder] < v[huidig]){
					swap(v[huidig],v[ouder]);
					huidig = ouder;
					ouder = (huidig - 1) / 2;
				}
			}
		}
		int aantal_kinderen(const int index, const int size)const{
			int aant = 0;
			if (2*index+2 < size){
				aant = 2;
			}
			else if (2*index+1 < size){
				aant = 1;
			}
			return aant;
		}
		/*void fix_heap(vector<T> &vec, int size) const{
            int i = 0;
            //Check if i is on the last row of the heap OR if i is bigger than its 2 children
            while((i+1)*2 < size && (vec[i] < vec[(i+1)*2 -1] || vec[i] < vec[(i+1)*2 +1 -1])){
                if(vec[(i+1)*2 -1] < vec[(i+1)*2 +1 -1]){        //IF child1 < child2 => swap parent with child2
                    int temp = vec[i];
                    vec[i] = vec[(i+1)*2 +1 -1 ];
                    vec[(i+1)*2 +1 -1] = temp;
                    i = (i+1)*2 +1 -1;
                }
                else {                                           //ELSE child1 > child2 => swap parent with child1
                    int temp = vec[i];
                    vec[i] = vec[(i+1)*2 -1];
                    vec[(i+1)*2 -1] = temp;   
                    i = (i+1) *2 - 1;
                } 
            }
        }*/
	
};
