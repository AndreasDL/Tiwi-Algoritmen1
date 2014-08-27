#include <iostream>
#include <vector>
using namespace std;

void sort3(vector<int> &v, int first, int mean, int last);
void short_insertionsort(vector<int> &v, int first, int last);

void quicksort(vector<int> &v, int min, int max){
    //Important indexes and size
    int first = min;
    int last = max-1;
    int mean = (last + first) /2;
    int size = max - min;
    
    //Sort the first, last and mean values
    sort3(v, first, mean, last);
    
    //Place the pivot on the penultimate position
    int pivot = last-1;
    int temp = v[pivot];
    v[pivot] = v[mean];
    v[mean] = temp;
    
    //Order the remaining values according to QuickSort
    int left = first;
    int right = last - 2;                               //Don't use the pivot
    
    while(left != right){
        if(v[left] <= v[pivot]){
            left++;
        }
        else if(v[right] > v[pivot]){
            right--;
        }
        else {
            int temp = v[left];
            v[left] = v[right];
            v[right] = temp;
        }
    }
    
    //Put the pivot back in place
    if(v[left] <= v[pivot]){
        left++;
    }
    if(left < pivot){                                  //If left == last-1 then the pivot is <= then
        int temp = v[left];                             // all of the other elements in this section
        v[left] = v[pivot];
        v[last-1] = temp;
    }
    
    //Recursive sorting
    if(left - min > 3){
        quicksort(v, min, left+1);
    } 
    else {
        short_insertionsort(v, first, last);
    }
    
    if(last-left > 3){
        quicksort(v, left, max);
    }
    else {
        short_insertionsort(v, first, last);
    }
}

void short_insertionsort(vector<int> &v, int first, int last){
    for(int i = first; i <= last; i++){
        int temp = v[i];
        int j = i -1;
        while(j >= first && temp < v[j]){
           v[j+1] = v[j];
           j--;
        }
        v[j+1] = temp;    
    }
}

void sort3(vector<int> &v, int first, int mean, int last){
    if(v[mean] < v[first]){
        int temp = v[mean];
        v[mean] = v[first];
        v[first] = temp;
    }
    if(v[last] < v[mean]){
        int temp = v[last];
        v[last] = v[mean];
        v[mean] = temp;   
        
        if(v[mean] < v[first]){
           int temp = v[mean];
           v[mean] = v[first];
           v[first] = temp;
        }
    }
}


int main(){
    srand(15);
    int MIN = 0;
    int MAX = 100;
    int DELTA = MAX - MIN;
    int N = 21;
    
    vector<int> v;
    
    cout<<"Initial vector:"<<endl;
    for(int i = 0; i < N; i++){
        v.push_back(rand()%DELTA + MIN);
        cout<<v[i]<<"\t";
    }
    cout<<"-----------------"<<endl;
    cout<<"QuickSort:"<<endl;
    vector<int> v2 = v;
    
    quicksort(v, 0, v.size());
    for(int i = 0; i < N; i++){
        cout<<v[i]<<"\t";
    }
    
    cout<<"-----------------"<<endl;
    cout<<"Std::Sort"<<endl;
    
    std::sort(v2.begin(), v2.end());
    for(int i = 0; i < N; i++){
        cout<<v2[i]<<"\t";
    }
    
    cout<<endl;
    
    for(int i = 0; i < N; i++){
        if(v[i] != v2[i]){
            cout<<"\nError in sorting :("<<endl;
            break;
        }
    }
    cout<<"\nSorting successful! :D"<<endl;
    
    cin.get();
    
    
    
}
