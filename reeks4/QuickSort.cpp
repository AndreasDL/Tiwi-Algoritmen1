#include <iostream>
#include <iomanip>
#include <vector>
#include "Sorteermethode.cpp"
#include <ctime> 
#include "chrono.h"

using namespace std;

/* Class Sorteermethode */
template <typename T>
class QuickSort:public Sorteermethode<T>{
	public:
		void operator() (vector<T> &v) const{
      if (v.size() > 1){// an array of zero or one elements is already sorted

        //select and remove a pivot value 'pivot' from 'array'
        //select pivot
        vector<T> w(3);
        w[0] = v[0];
        w[1] = v[v.size()/2];
        w[2] = v[v.size()-1];//mediaan nemen van eerste, middenste en laatste element
        std::sort(w.begin(),w.end());//sorteren
        T pivot = w[1];//mediaan = middenste :) 
        
        //maak groterdan en kleiner dan lijst
        vector<T> less(v.size());
        vector<T> greater(v.size());
        
        //vul die lijsten
        for (int i = 0 ; i < v.size() ; i++){
            if (v[i] <= pivot){
              less.push_back(v[i]);
            }else{
              greater.push_back(v[i]);  
            }
        }
        //RERERERERE_recurse
        v = concatenate(QuickSort<T>(less), QuickSort<T>(greater)); // two recursive calls
      }
		}
		vector<T> concatenate(vector<T> less,vector<T> greater){
      vector<T> v(less.size()+greater.size());
      for (int i = 0 ; i < less.size() ; i++){
          v[i] = less[i];
      }
      
      for (int i = 0 ; i < greater.size() ; i++){
        v[i+less.size()] = greater[i];  
      }
      
      return v;
		}
};
