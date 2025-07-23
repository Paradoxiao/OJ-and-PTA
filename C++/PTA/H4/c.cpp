#include <stdio.h>

#define MAXSIZE 20
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
  ElementType Data[MAXSIZE];
  Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput() {
  LNode *a = new LNode;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a->Data + i);
  }
  a->Last = n - 1;
  return a;
} /* 裁判实现，细节不表。元素从下标0开始存储 */
void PrintList(List L) {
  for (int i = 0; i <= L->Last; i++) {
    printf("%d ", L->Data[i]);
  }
} /* 裁判实现，细节不表 */
List Delete(List L, ElementType minD, ElementType maxD) {
  for (int i = 0; i <= L->Last; i++)
    if (L->Data[i] > minD && L->Data[i] < maxD) {
      for (int j = i; j <= L->Last; j++)
        L->Data[j] = L->Data[j + 1];
      L->Last--;
      i--;
    }
  return L;
}

int main() {
  List L;
  ElementType minD, maxD;
  int i;

  L = ReadInput();
  scanf("%d %d", &minD, &maxD);
  L = Delete(L, minD, maxD);
  PrintList(L);

  return 0;
}

/* 你的代码将被嵌在这里 */