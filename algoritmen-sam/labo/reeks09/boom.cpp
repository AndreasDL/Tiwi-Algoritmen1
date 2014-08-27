#include <iostream>
#include "boom.h"



using namespace std;

int main(){
	
	Boom<string> b("boom.txt", true);
	
	cout << "inorder: " ;
	b.schrijf_inorder();
	cout << endl;
	
	cout << "preorder: " ;
	b.schrijf_preorder();
	cout << endl;
	
	cout << "postorder: " ;
	b.schrijf_postorder();
	cout << endl;
	
	return 0;
}
