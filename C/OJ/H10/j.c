#include <stdio.h>
int isLegal(int data) {
  if (data >= 0 && data <= 100)
    return 1;
  return 0;
}
char grade(int data) {
  if (data >= 90)
    return 'A';
  if (data >= 80)
    return 'B';
  if (data >= 70)
    return 'C';
  if (data >= 60)
    return 'D';
  return 'E';
}
void print(char ch, int a, int b) {
  printf("%c:%6.2lf%%\n", ch, (float)a / b * 100);
}
int main() {
  int score, sum, sumGrade[5] = {0};
  sum = 0;
  while (scanf("%d", &score) != EOF) {
    if (isLegal(score)) {
      sum++;
      sumGrade[grade(score) - 'A']++;
    }
  }
  if (sum > 0) {
    for (int i = 0; i < 5; i++)
      print('A' + i, sumGrade[i], sum);
  }
}