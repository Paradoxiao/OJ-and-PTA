#include <iostream>
using namespace std;
class Apple {
private:
  double a, b, c;

public:
  void input() {
    cin >> a >> b >> c;
  }
  double value() {
    return a * b * c;
  }
};
int main() {
  int i, cases;
  Apple apple;

  cin >> cases;
  for (i = 1; i <= cases; i++) {
    apple.input();
    cout << apple.value() << endl;
  }
}