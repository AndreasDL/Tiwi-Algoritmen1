#include "Sorteer.h"
#include "Sorteermethode.h"
#include <iostream>

using namespace std;

void shuffle(vector<int> &vec){
    int curSize = vec.size();
    while(curSize > 0){
        int randI = rand()%curSize;
        int temp = vec[randI];
        vec[randI] = vec[vec.size()-1];
        vec[vec.size()-1] = temp;
    }   
}

int main(){
    
    int N = 10000;
    int MAX = 20;
    int MIN = 1;
    int DELTA = MAX - MIN;
    int CYCLI = 1;
    
    
    Sorteren<int> sorteren;
    InsertionSort<int> inSort;
    ShellSort<int> shSort;
    StdSort<int> stdSort;
    HeapSort<int> heapSort;
    
    vector<int> vecRandom;
    vector<int> vecUp;
    vector<int> vecDown;
    for(int i = 0; i < N; i++){
        vecRandom.push_back(rand()/*%DELTA*/ + MIN - 1);  
        vecUp.push_back(i);
        vecDown.push_back(N-i);      
    }
    
    
    /*
    cout<<"Insertion sort:\n\tCycli:\t"<<CYCLI<<"\n\tRandom\tAvg time:\t"<<sorteren.Sorteertijd(vecRandom, inSort, CYCLI)<<endl;
    cout<<"\tUp\tAvg time:\t"<<sorteren.Sorteertijd(vecUp, inSort, CYCLI)<<endl;
    cout<<"\tDown\tAvg time:\t"<<sorteren.Sorteertijd(vecDown, inSort, CYCLI)<<endl;
    */
    
    cout<<"Shell sort:\n\tCycli:\t"<<CYCLI<<"\n\tRandom\tAvg time:\t"<<sorteren.Sorteertijd(vecRandom, shSort, CYCLI)<<endl;
    cout<<"\tUp\tAvg time:\t"<<sorteren.Sorteertijd(vecUp, shSort, CYCLI)<<endl;
    cout<<"\tDown\tAvg time:\t"<<sorteren.Sorteertijd(vecDown, shSort, CYCLI)<<endl;
    
    cout<<"Std sort:\n\tCycli:\t"<<CYCLI<<"\n\tRandom\tAvg time:\t"<<sorteren.Sorteertijd(vecRandom, stdSort, CYCLI)<<endl;
    cout<<"\tUp\tAvg time:\t"<<sorteren.Sorteertijd(vecUp, stdSort, CYCLI)<<endl;
    cout<<"\tDown\tAvg time:\t"<<sorteren.Sorteertijd(vecDown, stdSort, CYCLI)<<endl;
    
    cout<<"Heap sort:\n\tCycli:\t"<<CYCLI<<"\n\tRandom\tAvg time:\t"<<sorteren.Sorteertijd(vecRandom, heapSort, CYCLI)<<endl;
    cout<<"\tUp\tAvg time:\t"<<sorteren.Sorteertijd(vecUp, heapSort, CYCLI)<<endl;
    cout<<"\tDown\tAvg time:\t"<<sorteren.Sorteertijd(vecDown, heapSort, CYCLI)<<endl;

    
    cin.get(); 
}
