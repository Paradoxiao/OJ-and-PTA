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
  // NOTE: 霍纳法则求解
  // x^4 + 2*x^3 + 3*x^2 + 4*x + 5 = (((((0)*x+1)*x+2)*x+3)*x+4)*x+5
  double getValue(double x) {
    // double sum = args[n], power = x;
    // for (int i = n - 1; i >= 0; i--) {
    //   sum += power * args[i];
    //   power *= x;
    // }
    // return sum;
    double result = 0;
    for (int i = 0; i <= n; i++)
      result = (result * x) + args[i];
    return result;
  }
};
int main() {
  int i, j, n, m, *a;
  double x;
  cin >> n;
  for (i = 0; i < n; i++) {
    Equation eq;
    cin >> m;
    a = new int[m + 1];
    for (j = 0; j <= m; j++)
      cin >> a[j];
    eq.setArgs(a, m);
    eq.print();
    cin >> x;
    cout << eq.getValue(x) << endl;
    delete[] a;
  }
  return 0;
}
