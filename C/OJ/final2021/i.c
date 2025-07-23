#include <stdio.h>
int count_array(int a[], int n, int v) {
  int N = 0;
  for (int i = 0; i < n; i++)
    if (a[i] == v)
      N++;
  return N;
}
int main() {
  int a[100], i, n, val, cnt;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  scanf("%d", &val);
  cnt = count_array(a, n, val);
  printf("%d\n", cnt);
}
