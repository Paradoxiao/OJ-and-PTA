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

/*

Description

我们知道，C++中的整数类型，如short、int、long和long long等都有确定的表示范围，超大的整数是不能表示的。请定义一个类Decimal，用于表示大整数，并实现如下方法：

1.根据给出的main函数定义的构造函数。

2. 重载加法（“+”）运算符，可以实现一个Decimal对象与另一个Decimal对象求和、与一个int类型的数值求和。

3. 重载前缀自增运算符。

4. 重载下标运算符，用于求当前对象的指定下标位置的数字。

5. 重载输入、输出运算符。
Input

输入3个数，前2个可能会超出unsigned long long的表示范围，最后1个是一个int类型的非负整数。

不考虑负数。
Output

见样例。
Sample Input
876543210012345678889
123456789987654321111
15
Sample Output
a = 876543210012345678889
b = 123456789987654321111
i = 15
a = 876543210012345678890
c = 1000000000000000000000
d = 876543210012345678890
e = 123456789987654321126
f = 554433
g = 12345
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
HINT

Append Code
append.cc,
[Submit][Status]

*/