#include <stdio.h>
int main() {
  int old, pre, change;
  scanf("%d", &pre);
  old = pre;
  while (scanf("%d", &change) != EOF) {
    old += change;
  }
  old >= pre ? puts("No") : puts("Yes");
  return 0;
}