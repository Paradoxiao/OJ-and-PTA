#include <iostream>
using namespace std;
class Equation {
private:
  int args[50], n;

public:
  void setArgs(int *a, int m) {
    for (int i = 0; i <= m; i++)
      args[i] = a[i];
    n = m;
  }
  void print() {
    bool find = false;
    for (int i = 0; i < n + 1; i++)
      if (args[i] != 0) {
        find = true;
        break;
      }
    if (!find) {
      cout << "0\n";
      return;
    }
    bool first = true;
    for (int i = 0; i < n + 1; i++)
      if (args[i] != 0) {
        if (!first && args[i] > 0)
          cout << "+";
        if (args[i] < 0)
          cout << "-";
        if ((args[i] != 1 && args[i] != -1) || i == n)
          cout << (args[i] >= 0 ? args[i] : -args[i]);
        if (i < n) {
          cout << "x";
          if (i < n - 1)
            cout << "^" << n - i;
        }
        first = false;
      }
    cout << endl;
  }
  double getValue(double x) {
    double sum = args[n], power = x;
    for (int i = n - 1; i >= 0; i--) {
      sum += power * args[i];
      power *= x;
    }
    return sum;
  }
  Equation operator+(const Equation &other) {
    Equation result;
    int max_n = n > other.n ? n : other.n;
    int res_args[51] = {0};
    for (int i = 0; i <= max_n; ++i) {
      int i1 = i + (n - max_n);
      int i2 = i + (other.n - max_n);
      int v1 = (i1 >= 0 && i1 <= n) ? args[i1] : 0;
      int v2 = (i2 >= 0 && i2 <= other.n) ? other.args[i2] : 0;
      res_args[i] = v1 + v2;
    }
    result.setArgs(res_args, max_n);
    return result;
  }
};
int main() {
  int j, m, *a;
  Equation eq1, eq2;
  cin >> m;
  a = new int[m + 1];
  for (j = 0; j <= m; j++)
    cin >> a[j];
  eq1.setArgs(a, m);
  eq1.print();
  delete[] a;

  cin >> m;
  a = new int[m + 1];
  for (j = 0; j <= m; j++)
    cin >> a[j];
  eq2.setArgs(a, m);
  eq2.print();
  delete[] a;

  (eq1 + eq2).print();
  return 0;
}
/*

Description
定义一个n阶多项式为：a0xn+a1xn-1+a2xn-2+...+an-2x2+an-1x+an。其中ai是系数，均为int类型内的整数。x是未知量，是一个double类型的实数。现在请定义Equation类来表示这个多项式。Equation类至少要有3个方法：

1. void Equation::setArgs(int a[], int n)：a是(n+1)个系数构成的数组，n是多项式的阶数。注意：系数个数比阶数多1。

2. void Equation::print()：用于输出方程。输出时xn输出x^n，且要按照我们平时惯用的方式来输出。包括如下规则：

（1）如果系数为0，则相应的项不输出。如果所有的系数为0，则只输出一个0。

（2）如果系数为1或-1，则不输出系数，仅输出对应的x的幂。

（3）一次项如果输出，不输出指数，即不输出x^1，而是x。

（4）0阶多项式即只有一个常数的多项式。

（5）按照从高阶到低阶的顺序输出。

3. 重载的加法运算符，实现两个多项式相加，相加的结果需要合并同类项。
Input

输入有4行。第1行、第3行是两个多项式的阶数，第2行、第4行是两个多项式的系数，按照从高阶到低阶的顺序输入。
Output

见样例。
Sample Input
4
1 2 3 4 5
4
5 4 3 2 1
Sample Output
x^4+2x^3+3x^2+4x+5
5x^4+4x^3+3x^2+2x+1
6x^4+6x^3+6x^2+6x+6
HINT

Append Code
append.cc,
[Submit][Status]

*/