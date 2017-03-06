#include <iostream>
#include <vector>

using namespace std;

#define tr(container, it)                                                      \
  for (decltype(container.begin()) it = container.begin();                     \
       it != container.end(); it++)

template <typename T> void reverse_array(T *begin, T *end) {
  // first decrement 'end' only for non-empty range
  if (begin != end) {
    end--;
    if (begin != end) {
      while (true) {
        swap(*begin, *end);
        begin++;
        if (begin == end)
          break;
        end--;
        if (begin == end)
          break;
      }
    }
  }
}

void printelem(int &elem) { cout << elem << "  "; }

int main() {

  int data[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
  vector<int> primes(data, data + (sizeof(data) / sizeof(data[0])));

  reverse_array(&primes[0], &primes[primes.size()]);

  for (int &elem : primes)
    cout << elem << "  ";
  cout << "\n";

  reverse_array(&primes.front(), &primes.back()+1);

  for (int &elem : primes)
    cout << elem << "  ";
  cout << "\n";
}

