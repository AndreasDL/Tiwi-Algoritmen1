#include <iostream>
#include "ThreadedTree.h"
using namespace std;

int main(){
	ThreadedTree<int> tree;
	tree.add(10);
	tree.add(7);
	tree.add(15);
	tree.add(3);
	tree.add(1);
	tree.printItemsInOrder();

	tree.remove(7);
	tree.printItemsInOrder();

	cin.get();
	return 0;
}