#include <iostream>
#include <vector>

using namespace std;

void makeHeap(vector<int> &vec){
    for(int i = 1 ; i <= vec.size(); i++){                      //<= omdat de gebruikswaarden = index+1
        int j = i;
        while(j > 1 && vec[j-1] > vec[j/2-1]){                  //Child > parent
            int hulp = vec[j-1];
            vec[j-1] = vec[j/2-1];
            vec[j/2-1] = hulp;
            j /=2 ;
        }
    }
}

void print(vector<int> &vec){
    cout<<"===================\n";
    for(int i = 0; i < vec.size(); i++){
        cout<<vec[i]<<endl;
    }
}

int main(){
    int N = 10;
    int MAX = 10;
    int MIN = 0;
    int DELTA = MAX - MIN;
    
    srand(5);
    
    vector<int> vec;
    
    for(int i = 0; i < N; i++){
        vec.push_back(rand()%DELTA + MIN - 1);
        cout<<vec[i]<<endl;
    }
    makeHeap(vec);
    print(vec);
    
    cin.get();
}
