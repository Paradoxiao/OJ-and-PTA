#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  int N;
  scanf("%d", &N);
  while (N--) {
    char num[2000];
    scanf("%s", num);
    printf((num[strlen(num) - 1] - '0') % 5 ? "No\n" : "Yes\n");
  }
  return 0;
}