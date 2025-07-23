#include <stdio.h>
#include <stdlib.h>
int main() {
  int N;
  scanf("%d", &N);
  while (N--) {
    char num[200];
    scanf("%s", num);
    int sum = 0;
    for (int i = 0; num[i] != '\0'; i++) {
      sum += num[i] - '0';
    }
    printf(sum % 3 ? "No\n" : "Yes\n");
  }
  return 0;
}