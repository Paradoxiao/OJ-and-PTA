#include <iostream>
using namespace std;
class Fract {
private:
  int n, m;

public:
  Fract(int n, int m) : n(n), m(m) {
    int a = n, b = m;
    int gcd = 1;
    a = a >= 0 ? a : -a;
    b = b >= 0 ? b : -b;
    while (b != 0) {
      int t = b;
      b = a % b;
      a = t;
    }
    gcd = a;
    if (gcd != 0) {
      this->n /= gcd;
      this->m /= gcd;
    }
  }
  Fract operator*(const Fract &f) {
    return Fract(n * f.n, m * f.m);
  }
  operator double() {
    if (n == 0)
      return 0;
    double a = n, b = m;
    return a / b;
  }
  void show() {
    if (n == 0) {
      cout << "0" << endl;
      return;
    }
    if (n * m < 0)
      cout << "-";
    cout << (n >= 0 ? n : -n);
    if (m != 1 && m != -1)
      cout << "/" << (m >= 0 ? m : -m);
    cout << endl;
  }
};
int main() {
  int n, m, p, q;
  while (cin >> n >> m >> q >> p) {
    Fract f1(n, m), f2(q, p);
    Fract fr = f1 * f2;
    fr.show();
  }
}