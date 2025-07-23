#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
  char name[100];
  double rate;
} teacher;
int main() {
  int i = 0, n, finaln = 0;
  teacher teachers[1000], final[1000];
  while (scanf("%d", &n) != EOF) {
    double a, b;
    scanf("%lf", &a);
    for (int j = 0; j < n; j++) {
      scanf("%s %lf", teachers[i].name, &b);
      teachers[i++].rate = b / a;
    }
  }
  for (int l = 0; l < i - 1; l++) {
    for (int k = 0; k < i - 1 - l; k++) {
      if (teachers[k].rate < teachers[k + 1].rate) {
        teacher temp = teachers[k + 1];
        teachers[k + 1] = teachers[k];
        teachers[k] = temp;
      }
    }
  }
  final[0] = teachers[0];
  for (int j = 0; j < i; j++) {
    int flag = 1;
    for (int k = 0; k < finaln; k++)
      if (!strcmp(final[k].name, teachers[j].name))
        flag = 0;
    if (flag)
      final[finaln++] = teachers[j];
  }
  for (int l = 0; l < finaln; l++)
    printf("%s %.2lf\n", final[l].name, final[l].rate);
  for (int l = 0; l < 3; l++)
    printf("%s\n", final[l].name);
  return 0;
}