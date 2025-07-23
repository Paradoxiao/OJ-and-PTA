#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
  int m, n;
  scanf("%d", &m);
  int ary1[m];
  for (int &i : ary1)
    scanf("%d", &i);
  scanf("%d", &n);
  int ary2[n];
  for (int &i : ary2)
    scanf("%d", &i);
  int ary3[m + n];
  int k = 0;
  for (int i = 0; i < m; i++)
    ary3[k++] = ary1[i];
  for (int j = 0; j < n; j++)
    ary3[k++] = ary2[j];
  sort(ary3, ary3 + m + n);
  for (int i = 0; i < m + n; i++)
    printf("%d ", ary3[i]);
  return 0;
}