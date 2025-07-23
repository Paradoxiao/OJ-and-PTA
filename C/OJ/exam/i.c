#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  char num[20];
  while (scanf("%s", num) != EOF) {
    int a[20];
    for (int i = 0, j = 1; i < strlen(num); i++) {
      if (isdigit(num[i]))
        a[j++] = num[i] - '0';
    }
    int rem = ((a[1] + a[3] + a[5] + a[7] + a[9] + a[11]) +
               (a[2] + a[4] + a[6] + a[8] + a[10] + a[12]) * 3) %
              10;
    puts((rem == 0 && a[13] == 0) || (rem != 0 && a[13] == 10 - rem) ? "YES"
                                                                     : "NO");
  }
  return 0;
}