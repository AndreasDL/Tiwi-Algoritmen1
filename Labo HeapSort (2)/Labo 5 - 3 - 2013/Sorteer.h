#ifndef SORTEER_H
#define SORTEER_H

#include <iostream>
#include <vector>
#include "chrono.h"
#include "Sorteermethode.h"

using namespace std;

template <typename T>
class Sorteren{
    public:
        double Sorteertijd(vector<T> &v, Sorteermethode<T> &sort, int ncycli=1);
};

template <typename T>
double Sorteren<T>::Sorteertijd(vector<T> &v, Sorteermethode<T> &sort, int ncycli){
    Chrono c;
    vector<double> times;
    for(int i = 0; i < ncycli; i++){
        vector<T> temp = v;
        c.start();
        sort(temp);
        c.stop();
        times.push_back(c.tijd());
    }
    
    
    double avg = 0.0;
    if(ncycli > 3){
        std::sort(times.begin(), times.end());
        for(int i = 1; i < times.size() -1; i++){
            avg += times[i];
        }
        avg /= (times.size()-1);
        
        return avg;
    }
    else {
        for(int i = 0; i < times.size(); i++){
            avg += times[i];
        }
        avg /= times.size();
        return avg;
    }
}
        
    
#endif    
