#include <stdio.h>

int pre[1010];
int find(int x);

int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
      pre[i] = i;

    for (int i = 0; i < m; i++) {
      int x, y;
      scanf("%d%d", &x, &y);

      int fx = find(x);
      int fy = find(y);

      if (fx != fy)
        pre[fx] = fy;
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
      if (pre[i] == i)
        cnt++;
    printf("%d\n", cnt);
  }

  return 0;
}

/* 请在这里填写答案 */
int find(int x) {
  if (pre[x] != x)
    return find(pre[x]);
  return pre[x];
}