#include <stdio.h>
#define MAX_LEN 100
void rev(char num[], int i) {
  if (num[i] == '\0') {
    return;
  }
  rev(num, i + 1);
  putchar(num[i]);
}
int main() {
  char num[MAX_LEN];
  gets(num);
  rev(num, 0);
}