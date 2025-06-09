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