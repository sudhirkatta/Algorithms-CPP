//Recursive program to evaluate prefix expressions
#include <iostream>
using namespace std;

char *a;
int i;

int eval() {
  int x = 0;
  while (a[i] == ' ')
    i++;
  if (a[i] == '+') {
    i++;
    return eval() + eval();
  }
  if (a[i] == '*') {
    i++;
    return eval() * eval();
  }
  while ((a[i] >= '0') && (a[i] <= '9'))
    x = 10 * x + (a[i++] - '0');
  return x;
}

int main() {
  char b[] = {'*', '+', '7', '*', '*', '4', '6', '+', '8', '9', '5', '\0'};
  a = b;
  eval();
  std::cout << i << std::endl;
}
