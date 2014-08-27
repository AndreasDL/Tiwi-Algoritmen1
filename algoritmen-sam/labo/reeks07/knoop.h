#include <string>
#include <vector>

#ifndef KNOOP
#define KNOOP
using namespace std;


class knoop{
	private:
		knoop* ouder;
		vector<knoop*> kinderen;
		char waarde;
	public:
		knoop(knoop *_ouder, char _waarde);
		~knoop();
		void voeg_kind_toe(knoop* kind);
		string toString();
		int getAantalKinderen();
		knoop* getOuder();
		char getWaarde();
};
#endif
