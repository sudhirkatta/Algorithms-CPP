#include <iostream>

using namespace std;

template<typename T> class InsertionSort{
    \
    void exch(T &A, T &B);
    void compexch(T &A, T &B);
public:
    void sort(T a[], int l, int r);

};

template <class T> void InsertionSort<T>::exch(T &A, T &B) {
  T t = A;
  A = B;
  B = t;
}

template <class T> void InsertionSort<T>::compexch(T &A, T &B) {
  if (B < A)
    exch(A, B);
}

template <class T> void InsertionSort<T>::sort(T a[], int l, int r) {
  int i;
  for (int i = r; i > l; i--)
    compexch(a[i - 1], a[i]);
  for (i = l + 2; i <= r; i++) {
    int j = i;
    T v = a[i];
    while (v < a[j - 1]) {
      a[j] = a[j - 1];
      j--;
    }
    a[j] = v;
  }
}

int main(int argc, char *argv[]) {
  int data[] = {2, 13, 5, 7, 11, 13, 7, 1, 3, 9, 31};

  InsertionSort<int> insertionSort;
  insertionSort.sort(data, 0, 11);

  for (int &elem : data)
    cout << elem << "  ";
  cout << "\n";
}
