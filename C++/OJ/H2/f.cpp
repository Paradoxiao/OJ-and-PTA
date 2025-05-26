#include <iostream>
using namespace std;
class Cx {
private:
  int a, b;

public:
  void re(int a) {
    this->a = a;
  }
  void im(int b) {
    this->b = b;
  }
  void print() {
    cout << "(" << a << "," << b << ")";
  }
};
int main() {
  Cx cc;
  int a, b;
  cin >> a >> b;
  cc.re(a);
  cc.im(b);
  cc.print();
}