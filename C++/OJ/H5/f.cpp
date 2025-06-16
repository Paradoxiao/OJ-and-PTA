#include <iostream>
#include <string>
using namespace std;
class Decimal {
private:
  int bit[1000];
  void carry() {
    for (int i = 0; i < 1000; i++)
      if (bit[i] >= 10) {
        bit[i + 1] += bit[i] / 10;
        bit[i] %= 10;
      }
  }

public:
  Decimal() : bit() {}
  Decimal(int a) : bit() {
    bit[0] = a;
    carry();
  }
  Decimal(string num) : bit() {
    int len = num.length();
    for (int i = 0; i < len; i++)
      bit[len - 1 - i] = num[i] - '0';
    carry();
  }
  Decimal operator+(const Decimal &a) const {
    Decimal res;
    for (int i = 0; i < 1000; i++)
      res.bit[i] = bit[i] + a.bit[i];
    res.carry();
    return res;
  }
  Decimal operator++() {
    bit[0]++;
    carry();
    return *this;
  }
  int getLength() const {
    for (int i = 999; i >= 0; i--)
      if (bit[i] != 0)
        return i + 1;
    return 1;
  }
  friend ostream &operator<<(ostream &os, const Decimal &a) {
    int len = a.getLength();
    for (int i = len - 1; i >= 0; i--)
      os << a.bit[i];
    return os;
  }
  friend istream &operator>>(istream &is, Decimal &a) {
    string num;
    is >> num;
    a = Decimal(num);
    return is;
  }
  int operator[](int index) const {
    return bit[getLength() - 1 - index];
  }
  friend Decimal operator+(const Decimal &a, int b) {
    Decimal res = a;
    res.bit[0] += b;
    res.carry();
    return res;
  }
};
int main() {
  Decimal a, b, c, d, e, f("554433"), g(12345);
  int i;
  cin >> a >> b >> i;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "i = " << i << endl;
  c = a + b;
  d = ++a;
  e = b + i;
  cout << "a = " << a << endl;
  cout << "c = " << c << endl;
  cout << "d = " << d << endl;
  cout << "e = " << e << endl;
  cout << "f = " << f << endl;
  cout << "g = " << g << endl;

  cout << c[0];
  for (i = 1; i < c.getLength(); i++) {
    cout << " " << c[i];
  }
  cout << endl;
  return 0;
}
