#ifndef __DIJKSTRA__
#define __DIJKSTRA__

#include <limits>
#include <queue>
#include <map>
#include "ggraaf.h"
using namespace std;

enum Kleur { WIT, GRIJS, ZWART };

// Bepaalt de kortste afstanden en ouders langs het kortste pad vanuit een vaste knoop.
// Verwacht een gerichte gewogen graaf zonder negatieve verbindingsgewichten.
template <class T>
class Dijkstra
{
private:
	//vector met de afstanden, wordt ingevuld door start(...) uit te voeren
    vector<int> afstanden;

public:
	T ONEINDIG;
	static const int OUDER_ONBEPAALD = -2;
	static const int GEEN_OUDER = -1;

	Dijkstra()
	{
		ONEINDIG = std::numeric_limits<int>::max();
	}

	// Voert het algoritme uit. 
	// Resultaten kunnen achteraf opgevraagd worden via de lidfuncties.
	// Gooit een GraafExceptie op indien de graaf negatieve gewichten heeft.
	void start(const GewogenGraaf<GERICHT, T> &g, int startk) 
	{  
        vector<bool> bezocht; //houdt bij of een knoop al bezocht is (zoja, kan er geen kortere afstand meer gevonden worden)
        afstanden.reserve(g.aantal_knopen());
        bezocht.reserve(g.aantal_knopen());
        
        //init afstanden: nul voor startknoop, oneindig voor de rest
		for(int i=0; i<g.aantal_knopen(); i++){
            afstanden[i] = ONEINDIG;
            bezocht[i] = false;
        }
        afstanden[startk] = 0;
        
        //queue voor knopen, startknoop erop
        queue<int> queue;
        queue.push(startk);
        
        //algoritme
        int huidig;
        while(!queue.empty()){
            huidig = queue.front(); //volgende knoop
            queue.pop();
            map<int, int> knoop = g[huidig]; //huidige knoop
            bezocht[huidig] = true; //huidig is bezocht (dwz, de gevonden afstand is sowieso de kortste)
            //alle buren overlopen
            for(std::map<int, int>::const_iterator it = knoop.begin(); it != knoop.end(); it++) {
				//3 hulpvariabelen
                int buur = it->first; //1
                int verbinding = it->second; //2
                int gewicht = g.gewicht(verbinding); //3
                if(afstanden[huidig] + gewicht < afstanden[buur]){
                    afstanden[buur] = afstanden[huidig] + gewicht; //kortere afstand gevonden
                }
                if(!bezocht[buur]){
                    queue.push(buur); //buren (die nog niet bezocht zijn) op de queue zetten
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
	int afstand(int k) const 
	{ 
		return afstanden[k];
	}
};

#endif
