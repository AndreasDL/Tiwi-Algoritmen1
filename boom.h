/*
 *  Binaire boom inlezen via regelnummers
 *  Binaire boom inlezen via sleutels (kan enkel indien er geen dubbele sleutels
 *                                     zijn)
 *  Binaire boom uitschrijven (in,pre,post,...)
 */

#include <iostream>
#include <fstream>  // lees bestand in!
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
	Knoop(const T &);
	void schrijf() const;
};

template <class T>
Boom<T>::Boom(){
	wortel = 0;	
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
    // ...
}

template <class T>
void Boom<T>::lees_via_sleutels(const string & bestandsnaam){
	cout<<"lees_via_sleutels nog niet geimplementeerd";
	// ...
}

template <class T>
void Boom<T>::schrijf_inorder()const{
	cout<<"schrijf_inorder nog niet geimplementeerd";
	// ...
}
template <class T>
void Boom<T>::schrijf_preorder()const{
	cout<<"schrijf_preorder nog niet geimplementeerd";
	// ...
}
template <class T>
void Boom<T>::schrijf_postorder()const{
	cout<<"schrijf_postorder nog niet geimplementeerd";
	// ...
}


template <class T>
Knoop<T>::Knoop(){	
}
template <class T>
Knoop<T>::Knoop(const T & t){
	sleutel = t;	
}
template <class T>
void Knoop<T>::schrijf() const{
	cout<<" "<<	sleutel;
}
