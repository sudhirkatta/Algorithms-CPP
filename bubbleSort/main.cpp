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

template <class Item> void bubbleSort(Item a[], int l, int r) {
  for (int i = l; i < r; i++)
    for (int j = r; j > i; j--)
      compexch(a[j - 1], a[j]);
}

int main(int argc, char *argv[]) {
  int data[] = {2, 13, 5, 7, 11, 13, 7, 1, 3, 9, 31};
  bubbleSort(data, 1, 11);

  for (int &elem : data)
    cout << elem << "  ";
  cout << "\n";
}
