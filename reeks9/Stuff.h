#ifndef stuff
#define stuff

template <typename T>
class IStuff{
  public:
    virtual boolean zijnGelijk(const T &t) const = 0;
    virtual int hashCode(const T &t) const = 0;
}

template <typename T>
class Stuff : public IStuff{
  public:
    Stuff Stuff(const T &t){
      t = _t;
    }
    boolean zijnGelijk(const T &t){
      return t == _t;
    }
    int hashCode(const T &t){
        
    }
  private T _t;
  
  }

#endif
