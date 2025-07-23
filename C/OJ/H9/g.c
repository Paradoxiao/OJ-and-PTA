#include <stdio.h>
#include <string.h>
int isHuiwen(char *a, int len) {
  char temp[1005] = {0}, tmp[1005] = {0};
  int i = 0;
  int n = 0;
  for (; n < len; n++) {
    if (a[n] >= 'A' && a[n] <= 'Z') {
      temp[i] = a[n] - 'A' + 'a';
      i++;
    }
    if (a[n] >= 'a' && a[n] <= 'z') {
      temp[i] = a[n];
      i++;
    }
    if (a[n] >= '0' && a[n] <= '9') {
      temp[i] = a[n];
      i++;
    }
  }
  for (n = 0; n <= i; n++) {
    tmp[n] = temp[i - n - 1];
  }
  return !strcmp(temp, tmp);
}

int main() {
#ifndef ONLINE_JUDGE
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
  char a[1005];
  while (gets(a) != NULL) {
    isHuiwen(a, strlen(a)) ? puts("Yes.") : puts("No.");
  }
  return 0;
}