#include <cstdio>
using namespace std;
void exch(int *l, int *r) {
  int temp;
  while (l < r) {
    temp = *l;
    *l = *r;
    *r = temp;
    l++;
    r--;
  }
}
int main() {
  int n, m, *l, *r;
  scanf("%d %d", &n, &m);
  int data[n];
  for (int &i : data)
    scanf("%d", &i);
  m = m % n;
  l = data;
  r = data + m - 1;
  exch(l, r);
  l = data + m;
  r = data + n - 1;
  exch(l, r);
  l = data;
  r = data + n - 1;
  exch(l, r);
  putchar('\n');
  for (int i = 0; i < n; i++)
    printf(i ? " %d" : "%d", data[i]);
  return 0;
}