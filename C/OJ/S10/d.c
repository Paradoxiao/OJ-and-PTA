#include <stdio.h>
int *findMax(int a[], int n) {
  int max = *a, temp, i;
  for (i = 0; i < n; i++) {
    if (max <= a[i]) {
      max = a[i];
      temp = i;
    }
  }
  return a + temp;
}
void inputArray(int a[], int n) {
  for (int i = 0; i < n; i++)
    scanf("%d", a + i);
}
int main() {
  int n, *p;
  scanf("%d", &n);
  int array[n];
  inputArray(array, n);
  p = findMax(array, n);
  printf("%d", *p);
  return 0;
}