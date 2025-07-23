#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getN(char a[], char b[]) {
  int n = 0;
  for (int i = 0; i < strlen(a) - strlen(b); i++) {
    char temp[1005];
    memcpy(temp, a + i, strlen(b));
    temp[strlen(b) + 1] = 0;
    if (strcmp(temp, b) == 0)
      n++;
  }
  return n;
}
int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    char a[1005], b[1005];
    scanf("%s %s", b, a);
    printf("%d\n", getN(a, b));
  }
  return 0;
}