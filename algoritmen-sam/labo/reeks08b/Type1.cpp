#ifndef type1
#define type1

#include <string>
using namespace std;

class Type1{
	private:
		string s;		
	public:
		Type1(const Type1 &t);
		Type1(string _s);
		string getString() const;
		int hashcode();
		bool equals(Type1 s2);	
};

Type1::Type1(string _s){
	s = _s;
}

Type1::Type1(const Type1 &t){
	s = t.getString();
}

string Type1::getString() const{
	return s;
}

int Type1::hashcode(){
	return s.length();
}

bool Type1::equals(Type1 s2){
	return s == s2.getString();
}

#endif
