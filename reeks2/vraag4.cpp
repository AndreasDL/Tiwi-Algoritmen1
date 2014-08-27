#include <iostream>
#include <vector>
using namespace std;
void fillVector(vector<point> &v,const int aantal,const int min, const int max);

struct point{
 public:
  int x , y;
  inline bool operator < (const point &p) const{
         return x == p.x? y < p.y : x < p.x;
         }
  point(const int x_ ,const int y_): x(x_) , y(y_){}
  
};
void fillVector(vector<point> &v, const int aantal,const int min, const int max);

int main(){
    vector<point> points;
    fillVector(points,10,0,10);
    for (int i = 0 ; i <points.size() ; i++){
        cout << points[i].x << ":" << points[i].y << endl;
        }
        
    std::sort(points.begin(),points.end());
    cout << "sorted" << endl;
    for (int i = 0 ; i <points.size() ; i++){
        cout << points[i].x << ":" << points[i].y << endl;
        }
    
    
    cin.get();
    return 0;
}

void fillVector(vector<point> &v,const int aantal,const int min, const int max){
    int hulp = max-min +1;
    for (int i =0 ; i < aantal ; i++){
        v.push_back( *(new point(rand()%hulp+min , rand()%hulp+min)) );
        }
}
