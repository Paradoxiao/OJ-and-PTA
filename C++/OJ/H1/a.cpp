#include <iostream>
using namespace std;
int main() {
  unsigned long long n, k;
  cin >> n >> k;
  unsigned long long pow = 1;
  for (int i = 0; i < k; i++)
    pow *= n;
  cout << pow;
  return 0;
}