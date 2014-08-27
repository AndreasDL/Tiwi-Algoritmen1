/*
 *  Binaire boom inlezen via regelnummers
 *  Binaire boom inlezen via sleutels (kan enkel indien er geen dubbele sleutels
 *                                     zijn)
 *  Binaire boom uitschrijven (in,pre,post,...)
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

template <class T>
class Knoop;

template <class T>
class Boom{
  protected:
	Knoop<T> * wortel;
	
    /* indien er zeker geen dubbels voorkomen, kan je inlezen via sleutels  */
	void lees_via_sleutels(const string & bestandsnaam);                
	
	/* 'standaard' inlezen gaat via regelnummers                            */
	void lees_via_regelnummers(const string & bestandsnaam);
	
  public:
	Boom();	
	Boom(const string & bestandsnaam, bool via_sleutels); 
	~Boom();
	void schrijf_inorder() const;
	void schrijf_preorder() const;
	void schrijf_postorder() const;
	void schrijf_levelorder() const;
};

template <class T>
class Knoop{
  friend class Boom<T>;	
  protected:	
	T sleutel;
	Boom<T> links,rechts;
	Boom<T> * ouder;
	Knoop();	
	~Knoop();
	Knoop(const T &);
	void schrijf() const;
};

template <class T>
Boom<T>::Boom(){
	wortel = 0;	
}

template <class T>
Boom<T>::~Boom(){
	if (wortel != 0){
		delete wortel;	
	}
}

template <class T>
Boom<T>::Boom(const string & bestandsnaam, bool via_sleutels=false){
    if(via_sleutels){
        lees_via_sleutels(bestandsnaam);   
    }
    else{
        lees_via_regelnummers(bestandsnaam);   
    }
}

template <class T>
void Boom<T>::lees_via_regelnummers(const string & bestandsnaam){
    cout<<"lees_via_regelnummers nog niet geimplementeerd";   
}

template <class T>
void Boom<T>::lees_via_sleutels(const string & bestandsnaam){
	ifstream in (bestandsnaam.c_str());
	
	if (!in.is_open()){
		throw "Kan bestand niet openen";
	}
	
	int index = 0;
	int n;
	T sleutel;
	int links;
	int rechts;
	
	// Aantal knopen inlezen
	in >> n;
	
	Knoop<T>** tabel = new Knoop<T>*[n];
	
	// vooraf opbouwen -> zorgen dat de tabel reeds opgevuld is
	// anders krijgen we problemen met verwijzingen
	for (int i = 0; i < n ; i++){
		tabel[i] = new Knoop<T>();	
	}
	
	while (index < n && !in.fail()){
		//inlezen
		in >> sleutel;
		
		in >> links;
		links--; // want index begint bij 0, niet bij 1
		links--; // want eerste lijn bevat enkel aantal knopen
		
		in >> rechts;
		rechts--;		
		rechts--;
		
		// sleutel instellen
		tabel[index] -> sleutel = sleutel;
		
		
		if (links >= 0){
			tabel[index] -> links.wortel = tabel[links];
			tabel[links] -> ouder = new Boom<T>();	
			tabel[links] -> ouder -> wortel = tabel[index];
		}		
		else{
			tabel[index] -> links.wortel = 0;
		}
			
			
		if (rechts >= 0){
			tabel[index] -> rechts.wortel = tabel[rechts];
			tabel[rechts] -> ouder = new Boom<T>();		
			tabel[rechts] -> ouder -> wortel = tabel[index];
		}		
		else{
			tabel[index] -> rechts.wortel = 0;
		}
		
		if (tabel[index] -> ouder != 0){
			cout << sleutel << " is een kind van " << tabel[index] -> ouder -> wortel -> sleutel << endl;
		}
		else{
			cout << sleutel << " heeft geen ouder"<< endl;
		}
		index++;		
	}
		
	in.close();
	
	// Wortel zoeken
	Knoop<T>* w = tabel[0];
	while (w -> ouder != 0){
		w = w -> ouder -> wortel;
	}
	wortel = w;
	cout << wortel -> sleutel << " is wortel" << endl;
	
	// Deze hebben we niet meer nodig.
	// De knopen blijven wel nog in het geheugen staan, enkel de tabel
	// die pointers naar deze knopen bevat wordt verwijderd.
	delete[] tabel;
}

template <class T>
void Boom<T>::schrijf_inorder()const{
	if (wortel -> links.wortel != 0){
		wortel -> links.schrijf_inorder();
	}
	wortel -> schrijf();
	if (wortel -> rechts.wortel != 0){
		wortel -> rechts.schrijf_inorder();
	}
}
template <class T>
void Boom<T>::schrijf_preorder()const{
	wortel -> schrijf();
	if (wortel -> links.wortel != 0){
		wortel -> links.schrijf_inorder();
	}
	if (wortel -> rechts.wortel != 0){
		wortel -> rechts.schrijf_inorder();
	}
}
template <class T>
void Boom<T>::schrijf_postorder()const{
	if (wortel -> links.wortel != 0){
		wortel -> links.schrijf_inorder();
	}
	if (wortel -> rechts.wortel != 0){
		wortel -> rechts.schrijf_inorder();
	}
	wortel -> schrijf();
}


template <class T>
Knoop<T>::Knoop(){	
}
template <class T>
Knoop<T>::~Knoop(){	
}

template <class T>
Knoop<T>::Knoop(const T & t){
	sleutel = t;	
}

template <class T>
void Knoop<T>::schrijf() const{
	cout<<" "<<	sleutel;
}
