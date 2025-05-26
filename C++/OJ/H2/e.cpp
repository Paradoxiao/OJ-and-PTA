#include <iostream>
using namespace std;
int func(int = 0, int = 0, int = 0);
int main() {
  int m;
  std::cin >> m;
  func();
  func(m, 100);
  func(m, 23, -5);
}

int func(int a, int b, int c) {
  std::cout << "Number " << a << " " << b << " " << c << std::endl;
  return 0;
}
