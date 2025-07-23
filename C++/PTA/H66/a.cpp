#include <iostream>
using namespace std;

#define MAXSIZE 100
typedef int Status;
typedef char SElemType;

typedef struct {
  SElemType *base;
  SElemType *top;
  int stacksize;
} SqStack;

Status InitStack(SqStack &S) {
  S.base = new SElemType[MAXSIZE];
  if (!S.base)
    exit(-2);
  S.top = S.base;
  S.stacksize = MAXSIZE;
  return 1;
}

Status Push(SqStack &S, SElemType e) {
  if (S.top - S.base == S.stacksize)
    return 0;
  *S.top++ = e;
  return 1;
}

Status Pop(SqStack &S, SElemType &e) {
  if (S.base == S.top)
    return 0;
  e = *--S.top;
  return 1;
}

int main() {
  SqStack s;
  int n, i;
  char c;
  InitStack(s);
  ;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> c;
    Push(s, c);
  }
  for (i = 0; i < n; i++) {
    Pop(s, c);
    cout << c << " ";
  }
  return 0;
}