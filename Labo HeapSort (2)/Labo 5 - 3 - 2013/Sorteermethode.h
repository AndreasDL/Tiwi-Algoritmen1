
#ifndef SORTEERMETHODE_H
#define SORTEERMETHODE_H

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Sorteermethode{
    public:
        virtual void operator()(vector<T> &v)=0;
};

template <typename T>
class InsertionSort : public Sorteermethode<T>{
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

template <typename T>
class ShellSort : public Sorteermethode<T>{
    public:
        void operator()(vector<T> &v){
            vector<int> tab;
            int N = 3;
            tab.push_back(1);
            while(N < v.size()/3){
                N = (N *3 -1)/ 2;
                tab.push_back(N);
            }
            for(int j = tab.size()-1; j >= 0 ; j--){
                int a = tab[j];
                for(int i = 1; i < v.size(); i++){
                    T hulp  = v[i];
                    int j = i - a;
                    while(j >=0 && hulp < v[j]){
                        v[j+a] = v[j];
                        j-=a;
                    }
                    v[j+a]=hulp;
                }      
            }
        }
};

template <typename T>
class HeapSort : public Sorteermethode<T>{
    public:
        void operator()(vector<T> &v){
            construeer_heap(v);
            for(int i = v.size() - 1 ; i > 0; i--){
                int temp = v[0];
                v[0] = v[i];
                v[i] = temp;
                fix_heap(v, i);
            }
        }
        
    private:
        void construeer_heap(vector<T> &v){
            for(int i = 1 ; i <= v.size(); i++){                    //<= omdat de gebruikswaarden = index+1
                int j = i;
                while(j > 1 && v[j-1] > v[j/2-1]){                  //Child > parent
                    int hulp = v[j-1];
                    v[j-1] = v[j/2-1];
                    v[j/2-1] = hulp;
                    j /=2 ;
                }
            }
        }
        void fix_heap(vector<T> &vec, int size){
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
        }
};

template <typename T>
class StdSort : public Sorteermethode<T>{
    public: 
        void operator()(vector<T> &v){
            std::sort(v.begin(), v.end());
        }
};

#endif
