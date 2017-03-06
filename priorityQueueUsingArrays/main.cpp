// Array implementation of a priority queue
#include <iostream>

template <class T> class PQ {
private:
  T *pq;
  int N;

public:
  PQ(int maxN) {
    pq = new T[maxN];
    N = 0;
  }

  int empty() const { return N == 0; }
  void insert(T item);
  T getmax();
  void exch(T &A, T &B);
};

template <class T> void PQ<T>::insert(T item) { pq[N++] = item; }

template <class T> void PQ<T>::exch(T &A, T &B) {
  T t = A;
  A = B;
  B = t;
}

template <class T> T PQ<T>::getmax() {
  int max = 0;
  for (int j = 1; j < N; j++)
    if (pq[max] < pq[j])
      max = j;
  exch(pq[max], pq[N - 1]);
  return pq[--N];
}

int main() {

  PQ<int> pq(4);
  pq.insert(5);
  pq.insert(2);
  pq.insert(7);
  pq.insert(4);

  std::cout << "Max Element: " << pq.getmax() << std::endl;
}
