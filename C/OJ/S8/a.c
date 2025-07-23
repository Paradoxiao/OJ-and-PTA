#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void fomat(char *in, char *out) {
  char temp[1005];
  memset(temp, 0, sizeof(temp));
  int i = 0, j = 0, flag = 1;
  for (i = 0; i < 1005; i++) {
    if (in[i] == '0' && flag)
      continue;
    else {
      flag = 0;
      temp[j++] = in[i];
    }
  }
  memcpy(out, temp, sizeof(in));
}
int main() {
  char in[1005], max[1005], min[1005];
  memset(in, 0, sizeof(in));
  memset(max, 0, sizeof(max));
  memset(min, 0, sizeof(min));
  scanf("%s", in);
  memcpy(max, in, sizeof(in));
  memcpy(min, in, sizeof(in));
  while (scanf("%s", in) != EOF) {
    fomat(in, in);
    memcpy(in, in, sizeof(in));
    if (strcmp(in, max) > 0) {
      memcpy(max, in, sizeof(in));
    }
    if (strcmp(in, min) < 0) {
      memcpy(min, in, sizeof(in));
    }
  }
  fomat(max, max);
  fomat(min, min);
  printf("The maximum value is : %s\nThe minimum value is : %s\n", max, min);
  return 0;
}