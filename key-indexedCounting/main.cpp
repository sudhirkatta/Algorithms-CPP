// Sorting by key index counting. The keys are stable
#include <iostream>
#include <vector>

using namespace std;

void distcount(int a[], int l, int r, int M, int maxN) {
  int i, j, cnt[M];
  int b[maxN];
  for (j = 0; j < M; j++)
    cnt[j] = 0;
  for (i = l; i <= r; i++)
    cnt[a[i] + 1]++;
  for (j = 1; j < M; j++)
    cnt[j] += cnt[j - 1];
  for (i = l; i <= r; i++)
    b[cnt[a[i]]++] = a[i];
  for (i = l; i <= r; i++)
    a[i] = b[i];
}

template <typename T>
void distcount(vector<T> &items, int left, int right, int numKeys) {

  int countKeys[numKeys]{};
  vector<T> b(items.size());

  // Number of keys less than each key
  for (int i = left; i <= right; i++)
    countKeys[items[i] + 1]++;

  // partial sum of indices
  for (int j = 1; j < numKeys; j++)
    countKeys[j] += countKeys[j - 1];

  // place items into position
  for (int i = left; i <= right; i++)
    b[countKeys[items[i]]++] = items[i];

  // copy sorted keys to given array
  for (int i = left; i <= right; i++)
    items[i] = b[i];
}

int main() {

    //using arrays
  cout << "using arrays"  <<"\n";
  int a[] = {0, 3, 3, 0, 1, 1, 0, 3, 0, 2, 0, 1, 1, 2, 0};
  distcount(a, 0, 14, 4, 14);
  for (int &elem : a)
    cout << elem << "  ";
  cout << "\n";

  //using vectors
  cout << "using vectors"  <<"\n";
  vector<int> c{0, 3, 3, 0, 1, 1, 0, 3, 0, 2, 0, 1, 1, 2, 0};
  distcount(c, 0, 14, 4);
  for (int &elem : c)
    cout << elem << "  ";
  cout << "\n";
}
