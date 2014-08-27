template <typename T>
void BUMergesort<T>::operator()(vector<T> &v)const{
  int size = v.size();
  vector<T> v2(v);
  for (int breedte = 1; breedte < size; breedte *= 2){
    for (int i = 0; i < size - breedte ; i += (2*breedte)){
      bumerge(v, i, i+breedte, min(i+2*breedte, size), v2);
    }
    v = v2;
  }
}

template <typename T>
void bumerge(vector<T> &v, int startlinks, int startrechts, int einde, vector<T> &v2){
  //2 gesorteerde vectoren mergen
  
  int linksindex = startlinks;
  int rechtsindex = startrechts;

  for (int j = startlinks; j < einde; j++){
    if (linksindex < startrechts && (rechtsindex >= einde || v[linksindex] <= v[rechtsindex])){
      v2[j] = v[linksindex];
      linksindex++;
    } else {
      v2[j] = v[rechtsindex];
      rechtsindex++;
    }
  }
}
