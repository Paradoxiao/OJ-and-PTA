#include <cstdio>
#include <iostream>
using namespace std;
class Solve {
  double a, b, c, rate, quick;
  void calcTax() {
    if (a <= 36000) {
      rate = 0.03;
      quick = 0;
      return;
    }
    if (a <= 144000) {
      rate = 0.10;
      quick = 2520;
      return;
    }
    if (a <= 300000) {
      rate = 0.20;
      quick = 16920;
      return;
    }
    if (a <= 420000) {
      rate = 0.25;
      quick = 21920;
      return;
    }
    if (a <= 660000) {
      rate = 0.30;
      quick = 52920;
      return;
    }
    if (a <= 960000) {
      rate = 0.35;
      quick = 85920;
      return;
    }
    {
      rate = 0.45;
      quick = 181920;
      return;
    }
  }

public:
  Solve(double a, double c) : a(a), c(c) {}
  void printResult() {
    calcTax();
    b = a * rate - quick;
    if (b < c - 1e-6) {
      printf("Drawback %.2f.\n", c - b);
      return;
    }
    if (b - c <= 400 + 1e-6) {
      printf("No operation.\n");
      return;
    }
    {
      printf("Supplement %.2f.\n", b - c);
    }
  }
};

int main() {
  double A, C;
  while (cin >> A >> C) {
    Solve solve(A, C);
    solve.printResult();
  }
}