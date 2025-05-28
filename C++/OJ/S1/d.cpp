#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
class MyString {
  char s[1100];
  bool echo() {
    for (char *p = s, *q = s + strlen(s) - 1; p < q; p++, q--)
      if (*p != *q)
        return 0;
    return 1;
  }

public:
  void input() {
    scanf("%s", s);
  }
  void output() {
    int len = strlen(s);
    if (echo())
      s[len / 2 + (len % 2 ? 1 : 0)] = '\0';
    printf("%s\n", s);
  }
};
int main() {
  MyString str;
  int n, i;
  cin >> n;
  for (i = 0; i < n; i++) {
    str.input();
    str.output();
  }
  return 0;
}