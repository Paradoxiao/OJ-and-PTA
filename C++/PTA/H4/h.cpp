#include <algorithm>
#include <stdio.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int a[n], b[m];
  for (int &i : a)
    scanf("%d", &i);
  for (int &i : b)
    scanf("%d", &i);
  sort(a, a + n);
  sort(b, b + m);
  int i = 0, j = 0;
  while (i < n && j < m) {
    if (a[i] < b[j]) {
      i++;
      continue;
    }
    if (a[i] > b[j]) {
      j++;
      continue;
    }
    for (int k = i-- + 1; k < n; k++)
      a[k - 1] = a[k];
    n--;
  }
  if (!n) {
    putchar('0');
    return 0;
  }
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
  return 0;
}