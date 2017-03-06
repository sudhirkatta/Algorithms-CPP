#include <iostream>

using namespace std;

template <class Item> void exch(Item &A, Item &B) {
  Item t = A;
  A = B;
  B = t;
}

template <class Item> void compexch(Item &A, Item &B) {
  if (B < A)
    exch(A, B);
}

template <class Item> void insertionSort(Item a[], int l, int r) {
  int i;
  for (int i = r; i > l; i--)
    compexch(a[i - 1], a[i]);
  for (i = l + 2; i <= r; i++) {
    int j = i;
    Item v = a[i];
    while (v < a[j - 1]) {
      a[j] = a[j - 1];
      j--;
    }
    a[j] = v;
  }
}

int main(int argc, char *argv[]) {
  int data[] = {2, 13, 5, 7, 11, 13, 7, 1, 3, 9, 31};
  insertionSort(data, 0, 11);

  for (int &elem : data)
    cout << elem << "  ";
  cout << "\n";
}
