#include <stdio.h>
#include <stdlib.h>
int ji_cmp(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}
int ou_cmp(const void *a, const void *b) {
  return *(int *)b - *(int *)a;
}
int main() {
  int num[1005], ji[1005], ou[1005], count = 0, jii, ouu;
  while (scanf("%d", &num[count]) != EOF)
    count++;
  jii = 0;
  ouu = 0;
  for (int i = 0; i < count; i++)
    if (i % 2)
      ou[ouu++] = num[i];
    else
      ji[jii++] = num[i];
  qsort(ji, jii, sizeof(int), ji_cmp);
  qsort(ou, ouu, sizeof(int), ou_cmp);
  jii = 0, ouu = 0;
  for (int i = 0; i < count; i++)
    printf(i ? " %d" : "%d", i % 2 ? ou[ouu++] : ji[jii++]);
  return 0;
}