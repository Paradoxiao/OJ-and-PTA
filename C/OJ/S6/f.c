#include <stdio.h>
int myFloor(double data) {
  int a = (int)data;
  return a > data ? a - 1 : a;
}
int myCeil(double data) {
  int a = (int)data;
  return a < data ? a + 1 : a;
}

int main() {
  double data;
  while (scanf("%lf", &data) != EOF)
    printf("%d %d\n", myFloor(data), myCeil(data));
  return 0;
}
