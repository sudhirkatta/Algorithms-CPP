#include <iostream>

using namespace std;

template<class Item>
void exch( Item &A, Item &B) {
    Item t = A;
    A = B;
    B = t;
}

template<class Item>
void selectionSort(Item a[], int l, int r) {
    for (int i = l; i < r; i++) {
       int min = i;
       for (int j = i + 1; j <= r; j++)
           if (a[j] < a[min])
               min = j;
       exch(a[i], a[min]);
    }
}

int main() {
    int data[] = {2, 13, 5, 7, 11, 13, 7, 1, 3, 9, 31};
    selectionSort(data, 1, 11);

    for (int &elem : data)
      cout << elem << "  ";
    cout << "\n";
}
