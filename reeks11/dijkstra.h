#ifndef __DIJKSTRA__
#define __DIJKSTRA__

#include <limits>
#include "ggraaf.h"
#include <priority_queue>
#include <pair>
using namespace std;

enum Kleur { WIT, GRIJS, ZWART };

// Bepaalt de kortste afstanden en ouders langs het kortste pad vanuit een vaste knoop.
// Verwacht een gerichte gewogen graaf zonder negatieve verbindingsgewichten.
template <typename T>
struct KnoopPair{
  int start;
  int stop;
  T value;
  inline bool operator < (const KnoopPair &k) const{
    return value < k.value;
  }
  inline bool operator > (const KnoopPair &k) const{
    return value > k.value
  }
  inline bool operator == (const KnoopPair &k) const{
    return k==k && value==value;  
  }
}


template <class T>
class Dijkstra
{
private:
  GewogenGraaf<T> min;
  
public:
	T ONEINDIG;
	static const int OUDER_ONBEPAALD = -2;
	static const int GEEN_OUDER = -1;

	Dijkstra()
	{
		ONEINDIG = std::numeric_limits<T>::max();
	}

	// Voert het algoritme uit. 
	// Resultaten kunnen achteraf opgevraagd worden via de lidfuncties.
	// Gooit een GraafExceptie op indien de graaf negatieve gewichten heeft.
	void start(const GewogenGraaf<GERICHT, T> &g, int startk) 
	{
		// ...
		vector<Kleur> bezocht(g.aantal_knopen());
		for (int i = 0 ; i < g.aantal_knopen; i++){
      bezocht[i] = ZWART;//niets bezocht
    }
    
    //we beginnen bij de startknoop 
		min.voeg_knoop_toe(startk); //startknoop in minimale boom steken
    bezocht[startk] = WIT;      //aanduiden als in boom.
    
    Priority_queue<KnoopPair<T> > kandidaten; //hierin zullen we alle kandidaten bijhouden 
                                              //die mogelijks toegevoegd kunnen worden aan 
                                              //de boom in de volgende iteratie
    int i = startk;                           //werken op knoop i startend bij startk
    
    //begin queue maken
    for (map<int,int>::iterator it= g[i].begin() ; it != g[i].end() ; it++){
      KnoopPair k;                //struct zodat we operator overloading kunnen doen
      k.start = i;                //startknoop
      k.stop  = it->first;        //stopknoop
      k.value = it->second;       //gewicht bijhouden
      kandidaten.push(k);         //inpriority queue steken
      bezocht[*it] = grijs;       //aanduiden als gezien
    }
    
    while (kandidaten.size() > 0){//herhalen zolang er nog knopen kunnen toegevoegd worden
      //kleinste toevoegen aan boom
      KnoopPair add = kandidaten.pop();   //kleinste => voorste in priority queue
      while(bezocht[add.stop] == WIT){    //zolang die knoop al in de boom
        add = kandidaten.pop();           //volgende nemen => vorige wordt uit pq gesmeten => opruimen van verbindingen naar knopen die al in de boom zitten.
      }
      //indien er nog een knoop over is
      min.voeg_knoop_toe(add.stop);                                   //knoop toevoegen aan boom
      min.voeg_verbinding_toe(add.start,add.stop,add.value)           //verbinding toevoegen aan boom
      bezocht[add.stop] = WIT;                                        //aanduiden als in boom
      
      //i opschuiven
      //i is nu de nieuw toegevoegde knoop zodat die verbindingen in de kandidaten queue komen
      i = add.stop;
      //alle knopen die (nieuw) aan de boom hangen in priority queue steken 
      //alle => nieuwe toevoegen want de vorige zitten er nog in
      for (map<int,int>::iterator it= g[i].begin() ; it != g[i].end() ; it++){
        KnoopPair k;                //struct zodat we operator overloading kunnen doen
        k.start = i;                //startknoop
        k.stop  = it->first;        //stopknoop
        k.value = it->second;       //gewicht bijhouden
        if (bezocht[it->first] != WIT){ //indien nog niet bezocht => vermijden dat we ouder knoop ook elke keer toevoegen
          //mss beter weglaten want this 1 ouder knoop die je 1 keer terug wegdoet en dit test je bij elke kandidaat.
          kandidaten.push(k);       //inpriority queue steken indien nog niet in boom
          bezocht[*it] = grijs;     //aanduiden als gezien
        }
      }
    }
	}

	
	// Geeft de ouder op het kortste pad van de startknoop naar knoop k.
	// Speciale gevallen: 
	// - GEEN_OUDER voor startknoop;
	// - OUDER_ONBEPAALD voor niet-bezochte knopen.
	int ouder(int k) const 
	{  
		// ...
	}

	// Geeft de totale lengte (totaal gewicht) van het kortste pad van de startknoop naar knoop k.
	// Speciaal geval:
	// - ONEINDIG voor niet bezochte knopen.
	T afstand(int k) const 
	{ 
		// ...
	}

	
};

#endif
