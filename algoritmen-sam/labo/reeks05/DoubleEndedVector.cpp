#include <iostream>
#include <vector>
#include "chrono.h"

using namespace std;

template <typename T>
class DoubleEndedVector{
	public:
		DoubleEndedVector();
		void push_back(T &item);
		void push_front(T &item);
		T pop_back();
		T pop_front();
		int size();
		const T& operator[](int i) const; // const moet er staan zodat de compiler 
								   // een onderscheid kan maken
		T& operator[](int i); 	   // referentie naar de plaats
	private:
		vector<T> front;
		vector<T> back;
};

template<typename T>
DoubleEndedVector<T>::DoubleEndedVector(){		
}

template<typename T>
void DoubleEndedVector<T>::push_back(T &item){
		back.push_back(item);
}

template<typename T>
void DoubleEndedVector<T>::push_front(T &item){
		front.push_back(item);
}

template<typename T>
T DoubleEndedVector<T>::pop_front(){
		if (front.size() == 0 && back.size() > 0){
			int split = (back.size() / 2)+1;
			for (int i = split-1; i >= 0; i--){
				front.push_back(back[i]);
			}
			for (int i = split; i < back.size(); i++){
				back[i-split] = back[i];
			}
			back.resize(back.size()-split);
		}
		
		T item = front.back();
		front.pop_back();
		return item;
		
}

template<typename T>
T DoubleEndedVector<T>::pop_back(){
		if (back.size() == 0 && front.size() > 0){
			int split = (front.size() / 2)+1;
			for (int i = split-1; i >= 0; i--){
				back.push_back(front[i]);
			}
			for (int i = split; i < front.size(); i++){
				front[i-split] = front[i];
			}
			front.resize(front.size()-split);
		}
		
		T item = back.back();
		back.pop_back();
		return item;
}

template<typename T>
int DoubleEndedVector<T>::size(){
		return front.size() + back.size();
}

template<typename T>
const T& DoubleEndedVector<T>::operator[](int i) const{
	if (i < front.size()){
		return front[front.size()-i-1];
	}	
	else{
		return back[i-front.size()];
	}
}

template<typename T>
T& DoubleEndedVector<T>::operator[](int i){
	if (i < front.size()){
		return front[front.size()-i-1];
	}	
	else{
		return back[i-front.size()];
	}
}

template<typename T>
bool assertEquals(T a, T b){
	return a == b;
}

bool unitTest(){
	cout << "[*] vooraan in, achteraan uit" << endl;
	DoubleEndedVector<int> dev;
	for (int i = 0; i < 20; i++){
		dev.push_front(i);
	}
	
	return false;
}

double benchmark(){
	Chrono c;
	c.start();
	DoubleEndedVector<int> dev;
	for (int i = 0; i < 200000; i++){
		dev.push_back(i);
	}
	while (dev.size() > 0){
		dev.pop_front();
	}
	c.stop();
	return c.tijd();
}

int main(){
	
	DoubleEndedVector<int> dev;
	
	for (int i = 0; i < 10; i++){
		dev.push_front(i);
	}
	
	for (int i = 10; i < 20; i++){
		dev.push_back(i);
	}
	for (int i = 0; i < dev.size(); i++){
		cout << "dev["<<i<<"] = " << dev[i] << " ";
	}
	cout << endl;
	while (dev.size() > 0){
		cout << dev.pop_back() << " ";
		//cout << dev.pop_front() << " ";
	}
	
	cout << endl;
	cout << benchmark() << endl;
	cout << ">>> ";
	cin.get();
	
	return 0;
}
