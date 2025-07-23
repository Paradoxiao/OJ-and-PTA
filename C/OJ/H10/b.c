#include <stdio.h>
int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int M, N, i = 0, show[100] = {0}, a, b, c;
  scanf("%d %d", &M, &N);
  char person[15][100] = {0}, out[20] = {0};
  for (int i = 0; i < N; i++)
    scanf("%s", person[i]);
  while (scanf("%s", out) != EOF) {
    switch (out[0]) {
    case 'S':
      show[0] = 1;
      break;
    case 'P':
      show[0] = 2;
      break;
    case 'R':
      show[0] = 3;
      break;
    }
    for (int i = 1; i < N; i++) {
      scanf("%s", out);
      switch (out[0]) {
      case 'S':
        show[i] = 1;
        break;
      case 'P':
        show[i] = 2;
        break;
      case 'R':
        show[i] = 3;
        break;
      }
    }
    a = b = c = 0;
    for (int i = 0; i < N; i++) {
      if (show[i] == 1)
        a = 1;
      if (show[i] == 2)
        b = 1;
      if (show[i] == 3)
        c = 1;
    }
    if (a + b + c == 3) {
      puts("No winner, no loser.");
      continue;
    }
    if (a + b + c == 1) {
      puts("Tie.");
      continue;
    }
    if (a + b + c == 2) {
      int first = 1;
      if (!a) {
        for (int i = 0; i < N; i++) {
          if (show[i] == 2) {
            if (first) {
              printf("%s", person[i]);
              first = 0;
            } else {
              printf(",%s", person[i]);
            }
          }
        }
        printf(" win ");
        first = 1;
        for (int i = 0; i < N; i++) {
          if (show[i] == 3) {
            if (first) {
              printf("%s", person[i]);
              first = 0;
            } else {
              printf(",%s", person[i]);
            }
          }
        }
        printf(".\n");
      }
      if (!b) {
        for (int i = 0; i < N; i++) {
          if (show[i] == 3) {
            if (first) {
              printf("%s", person[i]);
              first = 0;
            } else {
              printf(",%s", person[i]);
            }
          }
        }
        printf(" win ");
        first = 1;
        for (int i = 0; i < N; i++) {
          if (show[i] == 1) {
            if (first) {
              printf("%s", person[i]);
              first = 0;
            } else {
              printf(",%s", person[i]);
            }
          }
        }
        printf(".\n");
      }
      if (!c) {
        for (int i = 0; i < N; i++) {
          if (show[i] == 1) {
            if (first) {
              printf("%s", person[i]);
              first = 0;
            } else {
              printf(",%s", person[i]);
            }
          }
        }
        printf(" win ");
        first = 1;
        for (int i = 0; i < N; i++) {
          if (show[i] == 2) {
            if (first) {
              printf("%s", person[i]);
              first = 0;
            } else {
              printf(",%s", person[i]);
            }
          }
        }
        printf(".\n");
      }
    }
  }
  return 0;
}