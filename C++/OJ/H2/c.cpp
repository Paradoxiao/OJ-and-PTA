#include <iostream>
using namespace std;
class Equation {
private:
  int *args;
  int n;

public:
  Equation() : args(NULL), n(0) {}
  void setArgs(int *a, int m) {
    n = m;
    delete[] args;
    args = new int[m + 1];
    for (int i = 0; i < m + 1; i++)
      args[i] = a[i];
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
        if (args[i] != 1 && args[i] != -1 || i == n)
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
    double result = 0;
    for (int i = 0; i < n + 1; i++) {
      double pow = 1;
      for (int j = 0; j < n - i; j++)
        pow *= x;
      result += args[i] * pow;
    }
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