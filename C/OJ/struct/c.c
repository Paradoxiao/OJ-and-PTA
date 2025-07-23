#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  int n, first = 1;
  char num[10];
  scanf("%d %s", &n, num);
  while (n != 0 || num[0] != '0') {
    int bit, len = strlen(num);
    for (bit = 0; bit < len; bit++) {
      if (bit)
        putchar(' ');
      putchar(' ');
      for (int i = 0; i < n; i++)
        putchar(num[bit] == '2' || num[bit] == '3' || num[bit] == '5' ||
                        num[bit] == '6' || num[bit] == '7' || num[bit] == '8' ||
                        num[bit] == '9' || num[bit] == '0'
                    ? '-'
                    : ' ');
      putchar(' ');
    }
    putchar('\n');

    for (int i = 0; i < n; i++) {
      for (bit = 0; bit < len; bit++) {
        if (bit)
          putchar(' ');
        putchar(num[bit] == '4' || num[bit] == '5' || num[bit] == '6' ||
                        num[bit] == '8' || num[bit] == '9' || num[bit] == '0'
                    ? '|'
                    : ' ');
        for (int i = 0; i < n; i++)
          putchar(' ');
        putchar(num[bit] == '1' || num[bit] == '2' || num[bit] == '3' ||
                        num[bit] == '4' || num[bit] == '7' || num[bit] == '8' ||
                        num[bit] == '9' || num[bit] == '0'
                    ? '|'
                    : ' ');
      }
      putchar('\n');
    }

    for (bit = 0; bit < len; bit++) {
      if (bit)
        putchar(' ');
      putchar(' ');
      for (int i = 0; i < n; i++)
        putchar(num[bit] == '2' || num[bit] == '3' || num[bit] == '5' ||
                        num[bit] == '6' || num[bit] == '8' || num[bit] == '9' ||
                        num[bit] == '4'
                    ? '-'
                    : ' ');
      putchar(' ');
    }
    putchar('\n');

    for (int i = 0; i < n; i++) {
      for (bit = 0; bit < len; bit++) {
        if (bit)
          putchar(' ');
        putchar(num[bit] == '2' || num[bit] == '6' || num[bit] == '8' ||
                        num[bit] == '0'
                    ? '|'
                    : ' ');
        for (int i = 0; i < n; i++)
          putchar(' ');
        putchar(num[bit] == '1' || num[bit] == '5' || num[bit] == '3' ||
                        num[bit] == '4' || num[bit] == '7' || num[bit] == '8' ||
                        num[bit] == '9' || num[bit] == '0' || num[bit] == '6'
                    ? '|'
                    : ' ');
      }
      putchar('\n');
    }

    for (bit = 0; bit < len; bit++) {
      if (bit)
        putchar(' ');
      putchar(' ');
      for (int i = 0; i < n; i++)
        putchar(num[bit] == '2' || num[bit] == '3' || num[bit] == '5' ||
                        num[bit] == '6' || num[bit] == '8' || num[bit] == '9' ||
                        num[bit] == '0'
                    ? '-'
                    : ' ');
      putchar(' ');
    }
    putchar('\n');

    putchar('\n');
    scanf("%d %s", &n, num);
  }
  return 0;
}