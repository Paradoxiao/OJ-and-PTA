#include <stdio.h>
void max_min(int *max, int *min, int *arr, int n) {
  int Max = *arr, Min = *arr;
  for (int i = 1; i < n; i++) {
    if (Max < arr[i])
      Max = arr[i];
    if (Min > arr[i])
      Min = arr[i];
  }
  *max = Max;
  *min = Min;
}
int main() {
  int max, min, ar[100], i, n;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &ar[i]);
  max_min(&max, &min, ar, n);
  printf("%d %d\n", min, max);
  return 0;
}