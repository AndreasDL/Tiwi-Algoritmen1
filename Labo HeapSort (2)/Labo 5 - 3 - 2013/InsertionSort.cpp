#include "Sorteer.h"
#include "Sorteermethode.h"
#include <iostream>

using namespace std;

template <typename T>
class InsertionSort : public Sorteermethode{
    public:
        void operator()(vector<T> &v){
            for(int i = 1; i < v.size(); i++){
                T hulp = v[i];
                T j = i -1;
                while(j >= 0 && hulp < v[j]){
                    v[j+1] = v[j];
                    j--;
                }
                v[j+1] = hulp;
            }  
        }
};
