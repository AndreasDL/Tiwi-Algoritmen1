#ifndef _THREADEDTREE_H
#define	_THREADEDTREE_H

#include <string>
#include <stdexcept>
#include <vector>

typedef unsigned int uint;

class ThreadedTreeException : public std::logic_error {
public:
	ThreadedTreeException(const std::string &message_) : std::logic_error(message_) {}
};

template <typename T>
class ThreadedTree {
public:
	ThreadedTree(); //default constructor
	ThreadedTree(const std::vector<T> &items); //constructor
	~ThreadedTree(); //destructor
	void add(T item); //add an item if it doesn't exist
	void remove(const T& item); //remove an item if it exists
	bool contains(const T& item) const;
	T previousItem() const; //return item of predecessor if he exists otherwise throw ThreadedTreeException
	T nextItem() const; //return item of successor if he exists otherwise throw ThreadedTreeException
	std::vector<T> itemsInRange(const T& lower, const T& upper) const; //return vector of items where item is in ]lower, upper[
	uint size() const;
	void printItemsInOrder() const;
private:
	struct Node; //Node
	Node* root; //the root node
	uint _size;
	Node* firstNode(Node* root) const;
	Node* lastNode(Node* root) const;
	Node* previousNode(const Node* node) const;
	Node* nextNode(const Node* node) const;
	Node** findNode(const T &item);
	Node** getFirstNodeGreaterThan(const T &item) const; //return start node for itemsInRange
};

//************************************
//		implementation           
//************************************

template <typename T>
struct ThreadedTree<T>::Node {
	//constructor
	Node(T& _item):  leftChildNode(0),		//null pointer if no left child node and no predecessor
					 rightChildNode(0),		//null pointer if no right child node and no successor
					 hasPredecessor(false),	//true if leftChildNode contains pointer to the predecessor
					 hasSuccessor(false),	//true if rightChildNode contains pointer to the successor
					 item(_item) {}

	//destructor
	~Node(){
		if (leftChildNode != 0 && !hasPredecessor){
			delete leftChildNode;
		}
		if (rightChildNode != 0 && !hasSuccessor){
			delete rightChildNode;
		}
	}

	//children nodes
	Node* leftChildNode;
	Node* rightChildNode;

	//has predecessor and/or successor?
	bool hasPredecessor;
	bool hasSuccessor;

	//item
	T item;
};

template <typename T>
typename ThreadedTree<T>::Node* ThreadedTree<T>::firstNode(Node* root) const{ //don't forget typename!!!! 
	Node* node = root;
	while (node != 0 && node->leftChildNode != 0 && !node->hasPredecessor){
		node = node->leftChildNode;
	}
	return node;
}

template <typename T>
typename ThreadedTree<T>::Node* ThreadedTree<T>::lastNode(Node* root) const{ //don't forget typename!!!! 
	Node* node = root;
	while (node != 0 && node->rightChildNode != 0 && !node->hasSuccessor){
		node = node->rightChildNode;
	}
	return node;
}

template <typename T>
typename ThreadedTree<T>::Node* ThreadedTree<T>::previousNode(const Node* node) const{ //don't forget typename!!!! 
	return (node->hasPredecessor ? node->leftChildNode : lastNode(node->leftChildNode));
}

template <typename T>
typename ThreadedTree<T>::Node* ThreadedTree<T>::nextNode(const Node* node) const{ //don't forget typename!!!!
	return (node->hasSuccessor ? node->rightChildNode : firstNode(node->rightChildNode));
}


template <typename T>
typename ThreadedTree<T>::Node** ThreadedTree<T>::getFirstNodeGreaterThan(const T &item) const{ //don't forget typename!!!!
	return 0; //TODO
}

template <typename T>
typename ThreadedTree<T>::Node** ThreadedTree<T>::findNode(const T &item) { //don't forget typename!!!!
	Node** current = &root;
	while ((item < (*current)->item && !(*current)->hasPredecessor && (*current)->leftChildNode != 0) 
			|| (item > (*current)->item && !(*current)->hasSuccessor && (*current)->rightChildNode != 0)){
		if (item < (*current)->item){ //to left child tree
			current = &((*current)->leftChildNode);
		}
		else{ //to right child tree
			current = &((*current)->rightChildNode);
		}
	}
	return ((*current) != 0 && item == (*current)->item ? current : 0);
}

template <typename T>
ThreadedTree<T>::ThreadedTree(): root(0), _size(0){

}

template <typename T>
ThreadedTree<T>::ThreadedTree(const std::vector<T> &items): root(0), _size(0){
	for (uint i = 0; i < items.size(); i++){
		add(items[i]);
	}
}

template <typename T>
ThreadedTree<T>::~ThreadedTree(){
	if (root != 0){
		delete root;
	}
}

template <typename T>
void ThreadedTree<T>::add(T item){
	if (root == 0){ //first item (root)
		root = new Node(item);
		root->hasPredecessor = true;
		root->hasSuccessor = true;
		_size++;
	}
	else if (!contains(item)){
		Node* current = root;
		while ((item < current->item && !current->hasPredecessor && current->leftChildNode != 0) 
				|| (item > current->item && !current->hasSuccessor && current->rightChildNode != 0)){
			if (item < current->item){ //to left child tree
				current = current->leftChildNode;
			}
			else{ //to right child tree
				current = current->rightChildNode;
			}
		}
		if (item < current->item){
			Node* node = new Node(item);
			node->leftChildNode = current->leftChildNode;
			node->rightChildNode = current;
			node->hasPredecessor = true;
			node->hasSuccessor = true;
			current->leftChildNode = node;
			current->hasPredecessor = false;
		}
		else{
			Node* node = new Node(item);
			node->leftChildNode = current;
			node->rightChildNode = current->rightChildNode;
			node->hasPredecessor = true;
			node->hasSuccessor = true;
			current->rightChildNode = node;
			current->hasSuccessor = false;
		}
		_size++;
	}
}

template <typename T>
void ThreadedTree<T>::remove(const T& item){
	Node** node = findNode(item);
	if (node != 0){
		Node* successor = nextNode(*node);
		std::swap(*node, successor);
		(*node)->leftChildNode = successor->leftChildNode;
		successor->leftChildNode = 0;
		successor->rightChildNode = 0;
		delete successor;
		_size--;
	}
}

template <typename T>
bool ThreadedTree<T>::contains(const T& item) const{
	bool exist = false;
	Node* current = root;
	while (!exist && current != 0){
		if (item == current->item){
			exist = true;
		}
		else if (item < current->item){
			current = current->leftChildNode;
		}
		else{
			current = current->rightChildNode;
		}
	}
	return exist;
}

template <typename T>
T ThreadedTree<T>::previousItem() const{ //TODO
	if (leftChildNode == 0){
		throw ThreadedTreeException("There is no previous item.");
	}
	return (*previousNode())->item;
}

template <typename T>
T ThreadedTree<T>::nextItem() const{ //TODO
	if (rightChildNode == 0){
		throw ThreadedTreeException("There is no next item.");
	}
	return (*nextNode())->item;
}

template <typename T>
std::vector<T> ThreadedTree<T>::itemsInRange(const T& lower, const T& upper) const{ //TODO
	vector<T> temp;
	return temp;
}

template <typename T>
uint ThreadedTree<T>::size() const{
	return _size;
}

template <typename T>
void ThreadedTree<T>::printItemsInOrder() const{
	Node* node = firstNode(this->root);
	while (node != 0){
		cout << node->item << endl;
		node = nextNode(node);
	}
	cout << endl;
}

#endif //_THREADEDTREE_H