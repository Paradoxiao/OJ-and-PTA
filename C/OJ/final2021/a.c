#include <stdio.h>
struct student {
  int serial;
  double score;
  char level;
  char name[14];
};
int main() {
  printf("%lu", sizeof(struct student));
  return 0;
}