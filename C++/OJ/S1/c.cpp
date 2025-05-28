#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
class SpecialPrime {
public:
  static bool judge(int n) {
    if (n < 2)
      return 0;
    if (n == 2)
      return 1;
    for (int i = 2; i * i <= n; i++)
      if (n % i == 0)
        return 0;
    char num[100];
    sprintf(num, "%d", n);
    for (char *p = num, *q = num + strlen(num) - 1; p < q; p++, q--)
      if (*p != *q)
        return 0;
    return 1;
  }
};
int main() {
  int m, n, i;
  cin >> m >> n;
  for (i = m; i < n; i++) {
    if (SpecialPrime::judge(i))
      cout << i << endl;
  }
  return 0;
}