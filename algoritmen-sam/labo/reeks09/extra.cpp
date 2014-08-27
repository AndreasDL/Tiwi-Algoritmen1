#include <iostream>
#include "BinaireZoekboom.cpp"

using namespace std;
using namespace BinaireZoekboom;

int main(){
	Zoekboom<int> boom;
	boom.voegtoe(5);
	boom.voegtoe(89);
	boom.voegtoe(3);
	boom.voegtoe(12);
	boom.voegtoe(28);
	boom.voegtoe(1);
	boom.voegtoe(300);
	boom.voegtoe(55555);
	boom.voegtoe(287);
	boom.voegtoe(2);
	boom.voegtoe(18);
	boom.voegtoe(19);
	boom.voegtoe(4);
	boom.voegtoe(26);
	boom.voegtoe(299);
	boom.voegtoe(0);

	cout << "Boom 1 " << endl;
	boom.print();
	cout << endl;
	
	cout << 287 << " : " << boom.bevat(287) << endl;
	cout << 500 << " : " << boom.bevat(500) << endl;
	
	cout << "Hoogte: " << boom.hoogte() << endl;
	boom.maak_evenwichtig();
	cout << "Hoogte na evenwichtig maken: " << boom.hoogte() << endl;
	boom.print();
	

	Zoekboom<int> boom2;
	
	for (int i = 0; i < 23; i++){
		boom2.voegtoe(i);
	}
	cout << endl << endl << "Boom 2" << endl;
	boom2.print();
	cout << endl;
	cout << "Hoogte: " << boom2.hoogte() << endl;
	boom2.maak_evenwichtig();
	cout << "Hoogte na evenwichtig maken: " << boom2.hoogte() << endl;
	boom2.print();

	cin.get();
	return 0;
}
