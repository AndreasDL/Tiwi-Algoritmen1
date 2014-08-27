#include <iostream>
#include <stack>
#include <fstream>
#include <string>

using namespace std;

bool moet_sluiten(stack<int> wachters){
	//moet enkel een sluitend haakje tekenen als het element net onder het bovenste element in de stapel  NIET 1 groter is dan het bovenste element van de stapel
	if(wachters.size()>1){
		int bovenste = wachters.top();
		wachters.pop();
		return !(bovenste + 1 == wachters.top());
	}
	else
		return false;
}


string verwerk(string regel){  //eigenlijk is regel al een boom, maar je moet hem correct interpreteren. enkel de operators hebben/heeft kind(eren). je laatste char van regel is de root ;-)
    stack<int> wachters; //hierin wordt de posities (in de vector boom) van de operators die nog geen 2 in geval van +,-,*,/ en % of 1 in geval van ! en @ operandi hebben
    string resultaat;
	int regelpos = regel.length()-1;
	wachters.push(regelpos);
    while(!wachters.empty()){
		if((char)regel[wachters.top()]>='a' && (char)regel[wachters.top()]<='z'){
			//is letter
			resultaat = resultaat + regel[wachters.top()];
			if(moet_sluiten(wachters))
				resultaat = resultaat + ')';
			wachters.pop();
		}
		else{
			if((char)regel[wachters.top()]=='!' || (char)regel[wachters.top()]=='@'){
				// is ! of @
				if(regelpos == wachters.top()){
					//ziet teken voor eerste keer
					resultaat = resultaat + regel[wachters.top()] + '(';
					regelpos--;
					wachters.push(regelpos);
				}
				else{
					//ziet teken voor tweede keer
					wachters.pop();
					resultaat = resultaat + ')';
				}
			}	
			else{
				//is +, -, *, / of %
				if(regelpos == wachters.top()){
					//ziet teken voor éérste keer
					resultaat = resultaat + '(';
					regelpos--;
					wachters.push(regelpos);
				}
				else{
					//ziet het voor de 2de keer
					resultaat = resultaat + regel[wachters.top()];
					wachters.pop();
					if(moet_sluiten(wachters))
						resultaat = resultaat + ')';
					regelpos--;
					wachters.push(regelpos);
				}
			}
		}
    }
    resultaat = resultaat + ')';
    return resultaat;
}

int main(){
    //ifstream fin("formules_poolse_notatie.txt");
	ifstream fin("formules_poolse_notatie.txt");
    ofstream fout("formules_poolse_notatie_oplossing.txt");
    if(fin.is_open()){
        string regel;
        int i=0;
        while(fin.good()){
            getline(fin, regel);
            if(regel.length()>0){
            	fout<<regel<<endl<<"\t=>";
            	regel = verwerk(regel);
            	fout<<regel<<endl<<endl;
            }
        }
        cout<<"---------------einde-----------------"<<endl;
    }
    else
        cout<<"kon bestand \"formules_poolse_notatie.txt\" niet inlezen"<<endl;
        
    cin.get();
    return 0;
}
