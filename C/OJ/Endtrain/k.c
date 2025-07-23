#include <stdio.h>
#include <stdlib.h>
int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    int a, b, offred = 0, offblack = 0, redB = 0, redC = 0, blackB = 0,
              blackC = 0;
    scanf("%d", &a);
    char red[a + 1];
    for (int i = 0; i < a; i++)
      scanf(" %c", red + i);
    scanf("%d", &b);
    char black[b + 1];
    for (int i = 0; i < b; i++)
      scanf(" %c", black + i);
    for (int i = 0; i < a; i++)
      switch (red[i]) {
      case 'A':
        offred += 16;
        break;
      case 'B':
        offred += 7;
        redB = 1;
        break;
      case 'C':
        offred += 8;
        redC = 1;
        break;
      case 'D':
        offred += 1;
        break;
      case 'E':
        offred += 1;
        break;
      case 'F':
        offred += 2;
        break;
      case 'G':
        offred += 3;
        break;
      }
    for (int i = 0; i < b; i++)
      switch (black[i]) {
      case 'A':
        offblack += 16;
        break;
      case 'B':
        offblack += 7;
        blackB = 1;
        break;
      case 'C':
        offblack += 8;
        blackC = 1;
        break;
      case 'D':
        offblack += 1;
        break;
      case 'E':
        offblack += 1;
        break;
      case 'F':
        offblack += 2;
        break;
      case 'G':
        offblack += 3;
        break;
      }
    if (!redB || !redC)
      if (offred > 1)
        offred--;
    if (!blackB || !blackC)
      if (offblack > 1)
        offblack--;
    if (offblack > offred)
      puts("black");
    if (offred == offblack)
      puts("tie");
    if (offblack < offred)
      puts("red");
  }
  return 0;
}