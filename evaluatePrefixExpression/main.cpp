// Recursive program to evaluate prefix expressions
#include <iostream>
using namespace std;

template <typename T> class EvaluateExpression {
  char *a;
  int& i;

public:
  EvaluateExpression(char *a, int& i) : a(a), i(i) {}
  int eval();
};

template <typename T> int EvaluateExpression<T>::eval() {
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
  char expression[] = {'*', '+', '7', '*', '*', '4', '6', '+', '8', '9', '5', '\0'};
  int result;
  EvaluateExpression<int> evalexp(expression,result);

  evalexp.eval();
  std::cout << result << std::endl;
}
