#include <iostream>

int M = 4;

template <class Item> void exch(Item &A, Item &B) {
  Item t = A;
  A = B;
  B = t;
}

template <class Item> int partition(Item a[], int l, int r) {
  int i = l - 1, j = r;
  Item v = a[r];
  for (;;) {
    while (a[i++] < v)
      ;
    while (v < a[j--])
      if (j == l)
        break;
    if (j > i)
      break;
    exch(a[i], a[j]);
  }
  exch(a[i], a[r]);
  return i;
}

template <class Item> void compexch(Item &A, Item &B) {
  if (B < A)
    exch(A, B);
}

template <class Item> void quicksort(Item a[], int l, int r) {
  if (r - l <= M)
    return;
  exch(a[(l + r) / 2], a[r - 1]);
  compexch(a[l], a[r - 1]);
  compexch(a[l], a[r]);
  compexch(a[r - 1], a[r]);
  int i = partition(a, l + 1, r - 1);
  quicksort(a, l, i - 1);
  quicksort(a, i + 1, r);
}

template <class Item> void insertion(Item a[], int l, int r) {
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

template <class Item> void hybridsort(Item a[], int l, int r) {
  quicksort(a, l, r);
  insertion(a, l, r);
}

int main() {
  int data[] = {2, 13, 5, 7, 11, 13, 7, 1, 3, 9, 31};
  quicksort(data, 0, 11);

  for (int &elem : data)
    std::cout << elem << "  ";
  std::cout << "\n";
}
