#include <stdio.h>
#include <stdlib.h>
typedef struct {
  int lowTem, highTem, beauty;
  int bool, bollen;
} cloth;
int main() {
  int N, curTem, standard, found = 0, find = 0;
  scanf("%d %d %d", &curTem, &standard, &N);
  cloth clothes[N];

  for (int i = 0; i < N; i++) {
    scanf("%d %d %d", &clothes[i].lowTem, &clothes[i].highTem,
          &clothes[i].beauty);
    if (curTem >= clothes[i].lowTem && curTem <= clothes[i].highTem) {
      if (clothes[i].beauty >= standard) {
        clothes[i].bollen = 1;
        find = 1;
      }
      clothes[i].bool = 1;
      found = 1;
    }
  }

  if (found && find) {
    int maxbeauty = -2147483647, n = 0;
    for (int i = 0; i < N; i++) {
      if (clothes[i].bool == 1) {
        if (maxbeauty < clothes[i].beauty) {
          maxbeauty = clothes[i].beauty;
          n = i;
        }
      }
    }
    printf("Choose %d dress.", n + 1);
  }

  if (found && !find)
    puts("All the dress are ugly. Buy new one!");
  if (!found)
    puts("All the dress are inappropriate. Buy new one!");

  return 0;
}