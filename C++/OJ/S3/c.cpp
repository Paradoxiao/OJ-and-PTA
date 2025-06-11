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
  int n, m;
  while (cin >> n >> m) {
    Fract fr(n, m);
    cout << (double)fr << " ";
    fr.show();
  }
}