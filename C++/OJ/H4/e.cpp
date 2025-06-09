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