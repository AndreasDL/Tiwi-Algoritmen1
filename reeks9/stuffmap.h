#ifndef stuffmap
#define stuffmap

template <typename K,typename V>
class Stuffmap{
  private:
    int size;
    int MAX;
    vector< vector<V> > map;
    
    void rehash(){}
  public:
    Stuffmap Stuffmap(){
      map = vector<V>(MAX);
    }
    void add(const V &value,const K &key){
      map[key.hashCode() % MAX] = value;
      
    }
  }

#endif
