#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketsort(vector<int> &v);
int bepaal_min(vector<int> &v);
int bepaal_max(vector<int> &v);
void vul_random(vector<int> & v, int AANTAL, int MAX);
void perfect_random_shuffle(vector<int> & v);
void schrijf_uit(vector<int> & v, int AANTAL_PER_LIJN);
bool is_gesorteerd(vector<int> &v);

int main(){
    const int AANTAL = 100000;
    const int MAX = 100000;
    const int AANTAL_PER_LIJN = 10;
    
    //opvullen en shuffelen
    vector<int> v;
    vul_random(v, AANTAL, MAX);
    perfect_random_shuffle(v);
    
    /*******************************
    sorteermethode hier
    ******************************/
    bucketsort(v);
    
    
    if(is_gesorteerd(v)){
        cout << "v is gesorteerd!" << endl << endl;
        //schrijf_uit(v, AANTAL_PER_LIJN);
    } else {
        cout << "v is niet gesorteerd!" << endl;
    }
return 0;
}

void bucketsort(vector<int> &v){
    int size = v.size();
    int min = bepaal_min(v);
    int max = bepaal_max(v);
    int grootte = 10;
    int aant_interv = (max - min) / grootte + 1;
    
    //buckets maken
    vector< vector<int> > buckets;
    for(int i=0; i<aant_interv; i++){
        vector<int> bucket;
        buckets.push_back(bucket);
    }
    
    //alle elementen toevoegen aan juiste bucket
    for(int i=0; i<size; i++){
        int begin_interv = min; //begin beschouwde interval
        int nr = 0; //rangnummer beschouwde interval
        while(!(v[i] >= begin_interv && v[i] < (begin_interv + grootte))){
            //zolang niet in het beschouwde interval, volgende interval nemen
            begin_interv += grootte; //volgende interval
            nr++;
        }
        buckets[nr].push_back(v[i]); //v[i] toevoegen aan correcte bucket
    }
    
    //alle buckets sorteren
    for(int i=0; i<aant_interv; i++){
        std::sort(buckets[i].begin(), buckets[i].end());
    }
    
    /*
    //buckets uitschrijven: OK
    for(int i=0; i<aant_interv; i++){
        cout << "bucket nr: " << i << endl;
        schrijf_uit(buckets[i], 10);
        cout << endl;
    }
    */
    
    //buckets kopiëren naar originele vector
    int size_vorige = 0;
    for(int i=0; i<aant_interv; i++){
        for(int j=size_vorige; j<size_vorige+buckets[i].size(); j++){
            v[j] = buckets[i][j-size_vorige];
        }
        size_vorige += buckets[i].size();
    }
}

//bepaal kleinste element
int bepaal_min(vector<int> &v){
    int min = v[0];
    for(int i=1; i<v.size(); i++){
        if(v[i]<min){ min = v[i]; }
    }
    return min;
}

//bepaal grootste element
int bepaal_max(vector<int> &v){
    int max = v[0];
    for(int i=1; i<v.size(); i++){
        if(v[i]>max){ max = v[i]; }
    }
    return max;
}

//vul de vector met random getallen
//best hierna nog eens random shuffelen
void vul_random(vector<int> & v, int AANTAL, int MAX){
    for(int i=0; i<AANTAL; i++){
        v.push_back(rand()%MAX + 1);
    }
}

//vector door elkaar gooien
void perfect_random_shuffle(vector<int> & v){
    for(int i=v.size()-2; i>0; i--){
        int j = rand()%(i+1);
        int hulp = v[j];
        v[j] = v[i];
        v[i] = hulp;
    }
}

//uitschrijven met tabjes
void schrijf_uit(vector<int> & v, int AANTAL_PER_LIJN){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << "\t";
        if(i%AANTAL_PER_LIJN == AANTAL_PER_LIJN-1){
            cout << endl;
        }
    }
}

//controle gesorteerd: geen enkel element mag groter zijn dan zijn opvolger
bool is_gesorteerd(vector<int> &v){
    for(int i=0; i<v.size()-1; i++){
        if(v[i]>v[i+1]){ return false; }
    }
    return true;
}
