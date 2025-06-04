#include <iostream>
using namespace std;
class Data {
  int a;
  double b;

public:
  Data() {
    a = b = 2147483647;
    cout << "A default object is created.\n";
  }
  Data(int a) : a(a) {
    b = 2147483647;
    cout << "An integer object " << a << " is created.\n";
  }
  Data(double b) : b(b) {
    a = 2147483647;
    cout << "A double object " << b << " is created.\n";
  }
  ~Data() {
    if (a != 2147483647 && b == 2147483647) {
      cout << "The integer object " << a << " is erased.\n";
      return;
    }
    if (b != 2147483647 && a == 2147483647) {
      cout << "The double object " << b << " is erased.\n";
      return;
    }
    cout << "The default object is erased.\n";
  }
};
int main() {
  Data d1;
  int i;
  cin >> i;
  Data d2(i);
  double d;
  cin >> d;
  Data d3(d);
  return 0;
}
