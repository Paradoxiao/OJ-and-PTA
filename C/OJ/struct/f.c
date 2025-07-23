#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
  char name[25];
  char choice[25];
  int n;
} person;
int main() {
  int N, M, len;
  scanf("%d %d", &N, &M);
  person persons[N];
  for (int i = 0; i < N; i++) {
    scanf("%s", persons[i].name);
    for (int j = 0; j < M; j++)
      scanf(" %c", &persons[i].choice[j]);
    scanf("%d", &persons[i].n);
  }
  len = strlen(persons[0].name);
  for (int i = 1; i < N; i++)
    len = len > strlen(persons[i].name) ? len : strlen(persons[i].name);
  for (int i = 0; i < N; i++) {
    printf("%s", persons[i].name);
    for (int j = 0; j < len - strlen(persons[i].name); j++)
      putchar(' ');
    putchar(':');
    int flag = 1, first = 1;
    for (int l = 0; l < N; l++) {
      if (i != l) {
        int point = 0;
        for (int k = 0; k < M; k++)
          if (persons[i].choice[k] == persons[l].choice[k])
            point++;
        if (point >= persons[i].n) {
          printf(first ? "%s" : ",%s", persons[l].name);
          first = 0;
          flag = 0;
        }
      }
    }
    if (flag)
      printf("NONE!");
    putchar('\n');
  }
  return 0;
}