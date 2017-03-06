#include <iostream>

using namespace std;

template <class T> class BubbleSort {

private:
  void exch(T &A, T &B);
  void compexch(T &A, T &B);

public:
  void bubbleSort(T a[], int l, int r);
};

template <class T> void BubbleSort<T>::exch(T &A, T &B) {
  T t = A;
  A = B;
  B = t;
}

template <class T> void BubbleSort<T>::compexch(T &A, T &B) {
  if (B < A)
    exch(A, B);
}

template <class T> void BubbleSort<T>::bubbleSort(T a[], int l, int r) {
  for (int i = l; i < r; i++)
    for (int j = r; j > i; j--)
      compexch(a[j - 1], a[j]);
}

int main(int argc, char *argv[]) {
  int data[] = {2, 13, 5, 7, 11, 13, 7, 1, 3, 9, 31};
  BubbleSort bSort;
  bSort.bubbleSort(data, 1, 11);

  for (int &elem : data)
    cout << elem << "  ";
  cout << "\n";
}
