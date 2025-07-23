#include <stdio.h>
void print_graph(int n, char ch) {
  for (int l = n, ll = 0; l; l--, ll++) {
    for (int i = 0; i < ll; i++)
      putchar(' ');
    for (int i = 0; i < 2 * l - 1; i++)
      putchar(ch);
    putchar('\n');
  }
}
int main() {
  int n;
  char ch;
  while (scanf("%d%*c%c", &n, &ch) != EOF) {
    print_graph(n, ch);
  }
  return 0;
}
