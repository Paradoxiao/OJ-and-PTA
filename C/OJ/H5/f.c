#include <stdio.h>
int main() {
  int a;
  while (scanf("%d", &a) != EOF)
    switch (a) {
    case 90 ... 100:
      printf("Excellent\n");
      break;
    case 80 ... 89:
      printf("Good\n");
      break;
    case 70 ... 79:
      printf("Average\n");
      break;
    case 60 ... 69:
      printf("Pass\n");
      break;
    case 0 ... 59:
      printf("Failing\n");
      break;
    default:
      printf("Error\n");
      break;
    }
  return 0;
}