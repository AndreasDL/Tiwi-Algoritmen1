namespace Lijsten{
	
template <typename T>
class Lijstknoop;

template <typename T>
class Lijst{
   public:
      Lijst();
      Lijst(const Lijst &l);
      ~Lijst();
      //
      Lijst<T>& operator=(const Lijst<T> &l);
      void voeg_toe_vooraan(const T &d);
      void insertion_sort();
      void schrijf_uit();
      Lijstknoop<T> zoek_gerangschikt(T d);
   private:
      Lijstknoop<T>* k;
};
}
