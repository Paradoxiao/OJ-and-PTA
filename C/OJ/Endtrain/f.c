#include <stdio.h>
#define Odd 1
#define Even 0
int judge(int n) { return n % 2; }
int main() {
  int m;
  scanf("%d", &m);
  if (judge(m) == Odd)
    printf("Odd\n");
  if (judge(m) == Even)
    printf("Even");
}