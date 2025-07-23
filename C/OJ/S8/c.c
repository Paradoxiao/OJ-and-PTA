#include <stdio.h>
#include <stdlib.h>
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
  int n;
  scanf("%d", &n);
  char in[105];
  while (n--) {
    scanf("%s", in);
    for (int i = 0; i < 105; i++) {
      if (in[i] == '\0')
        break;
      else if (in[i] >= 'a' && in[i] <= 'z') {
        printf("%c", 'z' - in[i] + 'a');
      }
      if (in[i] >= 'A' && in[i] <= 'Z') {
        printf("%c", 'Z' - in[i] + 'A');
      }
    }
    putchar('\n');
  }
  return 0;
}