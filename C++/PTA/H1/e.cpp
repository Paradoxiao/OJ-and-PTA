#include <cstdio>
#include <vector>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> num(n + 1, 1);
  num[0] = num[1] = 0;
  for (int i = 2; i <= n; i++)
    if (num[i]) {
      int j = i * 2;
      if (j <= n)
        for (; j <= n; j += i)
          num[j] = 0;
    }
  for (int i = 2; i <= n; i++)
    if (num[i])
      printf("%6d", i);
  return 0;
}