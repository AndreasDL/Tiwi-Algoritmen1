#include <iostream>

using namespace std;

template <typename T>
class vector{
	private:
		int size;
		int capacity;
		T* data;
	public:
		vector(int _size);
		~vector();
		void voeg_toe(T item);
		void remove(int index);
		void print();
};

template <typename T>
vector<T>::vector(int cap=1){
	data = new T[cap];
	capacity = cap;
	size = 0;
}

template <typename T>
vector<T>::~vector(){
	delete[] data;
}

template <typename T>
void vector<T>::voeg_toe(T item){
	if (size == capacity){
		capacity *= 2;
		T* temp = new T[capacity];
		cout << "New vector : capacity : " << capacity << endl;
		for (int i = 0; i < size; i++){
			temp[i] = data[i];
		}
		delete[] data;
		data = temp;		
	}
	data[size] = item;
	cout << "Added item : " << item << endl;
	size++;
}

template <typename T>
void vector<T>::remove(int index){
	for (int i = index; i < size - 1; i++){
		data[i] = data[i+1];
	}
	size--;
}


template <typename T>
void vector<T>::print(){
	for (int i = 0; i < size ; i++){
		cout << data[i] << " : ";
	}
	cout << endl;
}

int main(){
	vector<int> v;
	for (int i = 0; i < 10; i++){
		v.voeg_toe(i);
	}
	v.print();
	v.remove(5);
	v.print();
	return 0;
}
