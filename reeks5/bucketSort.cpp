#include <iostream>
#include <vector>
#include "basics.h"
#include "chrono.h"
using namespace std;
template <typename T>
void insertionSort (vector<T> &v);
void bucketSort(vector<int> &v, const int min, const int max, const int n);

int main(){ 
  const int MIN=0;
  const int MAX=100000;
  const int AANTAL = 100000;
  const int N = 1000;
  Chrono c;
  
  for (int i = 1 ; i <= 10 ; i++){
    vector<int> v(i*AANTAL);
    fillVector(i*AANTAL,v,MIN,MAX);
    //print(v);
    c.start();
    bucketSort(v,MIN,MAX,N); 
    c.stop();
    //print(v);
    
    cout << "done! time: " << c.tijd() << " secs size: " << i*AANTAL << endl;
  }
  cin.get();
}

void bucketSort(vector<int> &v, const int min, const int max, const int n){
  //min en max waarden opgeven via klasse
  //vector => wat moet gesorteerd worden
  //n => aantal deel intervallen
  
  int intervalSize = (max-min)/n;
  vector<vector<int> >  deelInt(n);
  //vectoren aanmaken
  for (int i = 0 ; i < n ; i++){
    deelInt[i] = *(new vector<int>());
  }

  for (int i = 0 ; i < v.size() ; i++){
    //cout << "i:"  << i << " (v[i]-min)/intervalSize: " <<(v[i]-min)/intervalSize << " v[i]: " << v[i] << endl;
    deelInt[(v[i]-min-1)/intervalSize].push_back(v[i]); //in bucket steken
    //cout << "i: " << i << " / " << v.size() << endl;
  }

  for (int i = 0 ; i < n ; i++){
      insertionSort(deelInt[i]);
  }
  
  //terug in originele steken
  v.clear();
  for (int j = 0 ; j < n ; j++){
    for (int i = 0 ; i < deelInt[j].size() ; i++){
      v.push_back(deelInt[j][i]);
    }
  }
}

template <typename T>
void insertionSort (vector<T> &v){
	for(int i=1;i<v.size();i++){
		T h=v[i];
		int j=i-1;
		while(j>=0 && h<v[j]){
			v[j+1]=v[j];
			j--;
		}
		v[j+1]=h;
	}
}
