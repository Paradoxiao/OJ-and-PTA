#include <cstdio>
using namespace std;
int Ackermann(int m, int n) {
  switch (m) {
  case 0:
    return n + 1;
  case 1:
    return n + 2;
  case 2:
    return 2 * n + 3;
  case 3:
    return (1 << (n + 3)) - 3;
  case 4:
    if (n == 0)
      return 13;
    if (n == 1)
      return 65533;
  }
  return 0;
}

int main() {
  int m, n;
  while (scanf("%d %d", &m, &n) != EOF) {
    printf("%d\n", Ackermann(m, n));
  }
  return 0;
}
