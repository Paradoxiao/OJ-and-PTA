#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  char num[105];
  scanf("%s", num);
  int notfound = 1;
  for (int i = 0; i < strlen(num); i++) {
    if (isdigit(num[i])) {
      notfound = 0;
      printf("%c", num[i]);
    }
  }
  if (notfound)
    printf("null\n");
  return 0;
}