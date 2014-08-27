template <typename T>
void Heapsort<T>::operator()(vector<T> &v)const{
	construeer_heap(v);
	for (int i = v.size() -1; i > 0; i--){
		T temp = v[0];
		v[0] = v[i];
		v[i] = temp;
		
		int index = 0;
		while ((index+1)*2 < i && (v[index] < v[(index+1)*2 - 1] || v[index] < v[(index+1)*2])){
			if (v[(index+1)*2 -1] < v[(index+1)*2]){
				T temp = v[index];
				v[index] = v[(index+1)*2];
				v[(index+1)*2] = temp;
				index = (index+1)*2;
			}
			else {
				T temp = v[index];
				v[index] = v[(index+1)*2 - 1];
				v[(index+1)*2 - 1] = temp;
				index = (index+1)*2 - 1;
			}
		}
	}
}

template <typename T>
void construeer_heap(vector<T> &v){
  for (int i = 1; i <= v.size() ; i++){
    int j = i;
    while (j>1 && v[j-1] > v[j/2 - 1]){
      T h = v[j-1];
      v[j-1] = v[j/2 - 1];
      v[j/2-1] = h;
      j /= 2;
    }
  }
}
