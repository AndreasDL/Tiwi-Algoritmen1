#include <vector>
#ifndef __DIJKSTRA__
#define __DIJKSTRA__

#include <limits>
#include <map>
#include <queue>
#include "ggraaf.h"

using namespace std;

enum Kleur { WIT, GRIJS, ZWART };

// Bepaalt de kortste afstanden en ouders langs het kortste pad vanuit een vaste knoop.
// Verwacht een gerichte gewogen graaf zonder negatieve verbindingsgewichten.

struct knoopStruct {
	int knoopnr;
	double afstand;
};

struct knoop_compare  
{  
  bool operator()(const knoopStruct& l, const knoopStruct& r)  
  {  
      return l.afstand > r.afstand;  
  }  
};  


template <class T>
class Dijkstra
{
private:
	vector<T> afstanden;
	vector<int> ouders;
	

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
		int current = startk;
		bool* bezocht = new bool[g.aantal_knopen()];
		afstanden.resize(g.aantal_knopen());
		ouders.resize(g.aantal_knopen());
		
		for (int i = 0; i < g.aantal_knopen(); i++){
				afstanden[i] = ONEINDIG;
				ouders[i] =  OUDER_ONBEPAALD;
				bezocht[i] = false;
	    }
	   
	   afstanden[startk] = 0;
	   ouders[startk] = GEEN_OUDER;
	   bezocht[startk] = true;
			
		priority_queue<knoopStruct,vector<knoopStruct>, knoop_compare > pq;
		while (current >= 0){			
			
				
		
			// Elke buur van de huidige knoop behandelen
			map<int, int> buren = g[current];
			for (map<int, int>::iterator it = buren.begin(); it != buren.end(); it++){
				int knoop = it -> first;
				if (!bezocht[knoop]){
					double tempAfstand = afstanden[current] + g.gewicht(it -> second);
					if (tempAfstand < afstanden[it -> first]){
						afstanden[it -> first] = tempAfstand;	
						ouders[it -> first] = current;
						knoopStruct ks;
						ks.knoopnr = it -> first;
						ks.afstand = tempAfstand;
						pq.push(ks);
					}				
				}			
			}
			bezocht[current] = true;
		
			// Nieuwe huidige knoop bepalen
			/*
			current = -1;
			double min = ONEINDIG;
			for (int i = 0; i < g.aantal_knopen(); i++){
				if (!bezocht[i] && afstanden[i] < min){
					min = afstanden[i];
					current = i;
				}	
			}
			*/
			current = -1;
			if (! pq.empty()){
				current = pq.top().knoopnr;
				pq.pop();
			}
			
			while ( current >= 0 && bezocht[current]){
				current = -1;
				if (! pq.empty()){
					current = pq.top().knoopnr;
					pq.pop();
				}
			}
			
			
		}
		delete[] bezocht;
	}

	
	// Geeft de ouder op het kortste pad van de startknoop naar knoop k.
	// Speciale gevallen: 
	// - GEEN_OUDER voor startknoop;
	// - OUDER_ONBEPAALD voor niet-bezochte knopen.
	int ouder(int k) const 
	{  
		return ouders[k];
	}

	// Geeft de totale lengte (totaal gewicht) van het kortste pad van de startknoop naar knoop k.
	// Speciaal geval:
	// - ONEINDIG voor niet bezochte knopen.
	T afstand(int k) const 
	{ 
		return afstanden[k];
	}

	
};

#endif
