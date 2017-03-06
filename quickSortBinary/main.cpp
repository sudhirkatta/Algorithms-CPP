#include <iostream>

using namespace std;

const int bitsword = 32;
const int bitsbyte = 8;
const int bytesword = bitsword/bitsbyte;
const int R = 1 << bitsbyte;

inline int digit(long A, int B) {
  return (A >> bitsbyte * (bytesword - B - 1)) & (R - 1);
}

template<class Item>
void exch( Item &A, Item &B) {
    Item t = A;
    A = B;
    B = t;
}

template <class Item>
void quicksortB(Item a[], int l, int r, int d) {
  int i = l;
  int j = r;
  if (r <= l || d > bitsword)
    return;
  while (j != i) {
    while (digit(a[i], d) == 0 && (i < j))
      i++;
    while (digit(a[j], d) == 1 && (j > i))
      i--;
    exch(a[i], a[j]);
  }
  if (digit(a[r], d) == 0)
    j++;
  quicksortB(a, l, j - 1, d + 1);
  quicksortB(a, j, r, d + 1);
}

template <class Item> void sort(Item a[], int l, int r) {
  quicksortB(a, l, r, 0);
}

int main(int argc, char *argv[]) {
  int data[] = {2, 13, 5, 7, 11, 13, 7, 1, 3, 9, 31};
  sort(data, 1, 11);

  for (int &elem : data)
    cout << elem << "  ";
  cout << "\n";
}
