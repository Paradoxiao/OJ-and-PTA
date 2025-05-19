#include <cstdio>
using namespace std;
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    unsigned long long int a = 1;
    /* if (n == 2 || n == 3 || n == 5 || n == 7 || n == 13 || n == 17 || n == 19
     || n == 31 || n == 61) { for (int i = 0; i < n; i++) a *= 2;
       printf("%llu\n", a - 1);
     } else
       puts("no");*/
    switch (n) {
    case 2:
    case 3:
    case 5:
    case 7:
    case 13:
    case 17:
    case 19:
    case 31:
    case 61:
      for (int i = 0; i < n; i++)
        a *= 2;
      printf("%llu\n", a - 1);
      break;
    default:
      puts("no");
      break;
    }
  }
  return 0;
}
