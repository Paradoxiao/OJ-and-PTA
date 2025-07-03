#include <iostream>
using namespace std;
class Equation {
private:
  int args[50], n;

public:
  friend istream &operator>>(istream &is, Equation &eq) {
    int n;
    is >> n;
    for (int i = 0; i <= n; i++)
      is >> eq.args[i];
    eq.n = n;
    return is;
  }
  friend ostream &operator<<(ostream &os, const Equation &eq) {
    int n = 0;
    for (int i = 0; i <= eq.n; i++)
      if (eq.args[i] != 0) {
        n = eq.n - i;
        break;
      }
    os << n << " order polynomial:";
    bool find = false;
    for (int i = 0; i < eq.n + 1; i++)
      if (eq.args[i] != 0) {
        find = true;
        break;
      }
    if (!find) {
      os << "0\n";
      return os;
    }
    bool first = true;
    for (int i = 0; i < eq.n + 1; i++)
      if (eq.args[i] != 0) {
        if (!first && eq.args[i] > 0)
          os << "+";
        if (eq.args[i] < 0)
          os << "-";
        if ((eq.args[i] != 1 && eq.args[i] != -1) || i == eq.n)
          os << (eq.args[i] >= 0 ? eq.args[i] : -eq.args[i]);
        if (i < eq.n) {
          os << "x";
          if (i < eq.n - 1)
            os << "^" << eq.n - i;
        }
        first = false;
      }
    os << endl;
    return os;
  }
};
int main() {
  int n, i;
  cin >> n;
  for (i = 0; i < n; i++) {
    Equation eq;
    cin >> eq;
    cout << eq;
  }
  return 0;
}
/*

Description

定义一个n阶多项式为：a0xn+a1xn-1+a2xn-2+...+an-2x2+an-1x+an。其中ai是系数，均为int类型内的整数。x是未知量，是一个double类型的实数。现在请定义Equation类来表示这个多项式。

1.重载的>>运算符，按照格式要求读取方程。

2. 重载的<<运算符：用于输出方程。输出时xn输出x^n，且要按照我们平时惯用的方式来输出。包括如下规则：

（1）如果系数为0，则相应的项不输出。如果所有的系数为0，则只输出一个0。

（2）如果系数为1或-1，则不输出系数，仅输出对应的x的幂。

（3）一次项如果输出，不输出指数，即不输出x^1，而是x。

（4）0阶多项式即只有一个常数的多项式。

（5）按照从高阶到低阶的顺序输出。

（6）输出方程前，先按照样例格式输出各个方程的阶数。其中阶数定义为第一个非0系数对应的阶，如果只有常数项，则为0阶。
Input

输入有多行。

第一行N表示后面后N组测试用例。

每组测试用例包括2行。第1行n表示输入的系数的个数（不包括常数项），第2行输入n+1个int范围内的整数 ，是该多项式的系数，按照从高阶到低阶的顺序输入。

注意：每个测试用例的系数，可能前面若干个都是0，此时的阶数不等于n。
Output

见样例。
Sample Input
6
3
100 0 0 -1
3
100 -1 -1 -1
3
-1 -1 -1 -1
3
0 0 0 -1
3
0 -1 0 0
3
-100 0 0 -1
Sample Output
3 order polynomial:100x^3-1
3 order polynomial:100x^3-x^2-x-1
3 order polynomial:-x^3-x^2-x-1
0 order polynomial:-1
2 order polynomial:-x^2
3 order polynomial:-100x^3-1
HINT

Append Code
append.cc,
[Submit][Status]

*/