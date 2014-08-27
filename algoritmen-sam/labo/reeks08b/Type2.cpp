#ifndef type2
#define type2

#include <string>
using namespace std;

class Type2{
	private:
		int s;		
	public:
		Type1(int _s);
		int getValue();
		int hashcode();
		bool equals(Type2 s2);	
};

Type1::Type2(int _s){
	s = _s;
}

int Type2::getValue(){
	return s;
}

int Type2::hashcode(){
	return s;
}

bool Type2::equals(Type2 s2){
	return s == s2;
}

#endif
