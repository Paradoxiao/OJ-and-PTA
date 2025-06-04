#include <iostream>
using namespace std;
class Equation {
private:
  int args[5];

public:
  Equation() : args() {}
  void print() {
    bool find = false;
    for (int i = 0; i < 5; i++)
      if (args[i] != 0) {
        find = true;
        break;
      }
    if (!find) {
      cout << "0\n";
      return;
    }
    bool first = true;
    for (int i = 0; i < 5; i++)
      if (args[i] != 0) {
        if (!first && args[i] > 0)
          cout << "+";
        if (args[i] < 0)
          cout << "-";
        if ((args[i] != 1 && args[i] != -1) || i == 4)
          cout << (args[i] >= 0 ? args[i] : -args[i]);
        if (i < 4) {
          cout << "x";
          cout << "^" << 4 - i;
        }
        first = false;
      }
    cout << endl;
  }
  void setArgs(int a[]) {
    for (int i = 0; i < 5; i++)
      args[i] = a[i];
  }
  double getValue(double x) {
    double result = 0;
    for (int i = 0; i < 5; i++) {
      double pow = 1;
      for (int j = 0; j < 4 - i; j++)
        pow *= x;
      result += args[i] * pow;
    }
    return result;
  }
};
int main() {
  int i, a[5];
  double x;
  Equation eq1;
  cout << "1:";
  eq1.print();
  for (i = 0; i < 5; i++)
    cin >> a[i];
  eq1.setArgs(a);
  cout << "2:";
  eq1.print();
  cin >> x;
  cout << eq1.getValue(x) << endl;
  return 0;
}
