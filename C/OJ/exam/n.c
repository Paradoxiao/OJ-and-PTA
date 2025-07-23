#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  long double a, b;
  while (scanf("%Lf %Lf", &a, &b) != EOF) {
    long double c = a / b;
    char shang[100];
    int i;
    sprintf(shang, "%.20Lf", c);
    for (i = 0; i < strlen(shang); i++)
      if (shang[i] == '.')
        break;
    strcpy(shang, shang + i + 1);
    if (shang[strlen(shang) - 1] == '0') {
      printf("0\n");
      continue;
    }
    int found = 0;
    for (int i = 1; i < strlen(shang); i++) {
      char shang1[100], shang2[100];
      strncpy(shang1, shang, i);
      strncpy(shang2, shang + i, i);
      shang1[i] = '\0';
      shang2[i] = '\0';
      if (strcmp(shang1, shang2) == 0) {
        printf("%s\n", shang1);
        found = 1;
        break;
      }
    }
    if (!found) {
      printf("%s\n", shang);
    }
  }
  return 0;
}