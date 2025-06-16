#include <iostream>
using namespace std;
class Logical {
private:
  int a, b;
  char op;

public:
  Logical(int a, int b, char op) : a(a), b(b), op(op) {}
  bool value() {
    switch (op) {
    case '+':
      return a ^ b;
    case '-':
      return !(a ^ b);
    case '*':
      return a & b;
    case '/':
      return a | b;
    }
    return -1;
  }
  void show() {
    cout << a << " " << op << " " << b << " = " << value() << endl;
  }
};
int main() {
  int a, b;
  char ch;
  while (cin >> a >> ch >> b) {
    Logical log(a, b, ch);
    log.show();
  }
  return 0;
}
