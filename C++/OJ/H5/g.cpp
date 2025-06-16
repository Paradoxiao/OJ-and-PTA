#include <cstdio>
#include <iostream>
using namespace std;
class Expression {
private:
  int a, b;
  char op;

public:
  Expression(int a, int b, char op) : a(a), b(b), op(op) {}
  int value() {
    switch (op) {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
    case '/':
      return a / b;
    }
    return -1;
  }
  void show() {
    printf("%d %c %d = %d\n", a, op, b, value());
  }
};
int main() {
  int N, i, a, b;
  char op;
  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    cin >> a >> op >> b;
    Expression exp(a, b, op);
    exp.show();
  }
  return 0;
}
