#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct {
  ElemType *elem;
  int length;
} SqList;
void InitList(SqList &L) {
  L.length = 0;
  int a;
  std::cin >> a;
  while (a != -1) {
    L.elem[L.length++] = a;
    std::cin >> a;
  }
} /*细节在此不表*/
int PositiveInt(SqList L) {
  int i;
  int count = 0;
  for (i = 0; i < L.length; i++)
    if (L.elem[i] > 0)
      count++;
  return count;
}
int main() {
  SqList L;
  InitList(L);
  printf("The number of positive integers is %d.\n", PositiveInt(L));
  return 0;
}

/* 请在这里填写答案 */