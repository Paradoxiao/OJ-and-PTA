#include <stdio.h>
int main() {
  int a;
  while (1) {
    scanf("%d", &a);
    if (a == 0)
      break;
    printf("%d", a);
    switch (a % 10) {
    case 1:
      printf("st\n");
      break;
    case 2:
      printf("nd\n");
      break;
    case 3:
      printf("rd\n");
      break;
    default:
      printf("th\n");
      break;
    }
  }
  return 0;
}