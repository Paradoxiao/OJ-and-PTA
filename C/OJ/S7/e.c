#include <stdio.h>
#include <stdlib.h>
int main() {
  int a[20];
  int max, se;
  for (int i = 0; i < 15; i++)
    scanf("%d", a + i);
  max = a[0];
  se = -2147483647;
  for (int i = 1; i < 15; i++)
    max = max > a[i] ? max : a[i];
  for (int i = 0; i < 15; i++)
    if (a[i] > se && a[i] < max)
      se = a[i];
  printf("%d", se);
  return 0;
}