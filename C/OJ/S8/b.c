#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
  int n, ch;
  char in[25];
  memset(in, '\0', sizeof(in));
  scanf("%d", &n);
  while (n--) {
    scanf("%s", in);
    ch = 0;
    for (int i = 1; i < 25; i++)
      if (in[i] > in[ch])
        ch = i;
    for (int i = 0; i <= ch; i++) {
      printf("%c", in[i]);
    }
    printf("%c", '1');
    for (int i = ch + 1; i < 25; i++) {
      if (in[i] != '\0')
        printf("%c", in[i]);
    }
    printf("\n");
  }

  return 0;
}