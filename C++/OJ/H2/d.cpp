#include <iostream>
void get_num(int &a, int &b) {
  std::cin >> a >> b;
}
void put_sum(int a, int b) {
  std::cout << a + b;
}
int main() {
  int a, b;
  get_num(a, b);
  put_sum(a, b);
}
