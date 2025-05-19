#include <iostream>
using namespace std;
int num(int n) {
  if (n == 1)
    return 1;
  return num(n - 1) + n - 1;
}
int main() {
  int n;
  cin >> n;
  cout << num(n);
  return 0;
}