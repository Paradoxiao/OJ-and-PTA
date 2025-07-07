#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
typedef int KeyType;
typedef struct {
  KeyType *elem; /*elem[0]一般作哨兵或缓冲区*/
  int Length;
} SqList;
void CreatSqList(SqList *L); /*待排序列建立，由裁判实现，细节不表*/
int Partition(SqList L, int low, int high);
void Qsort(SqList L, int low, int high);
int main() {
  SqList L;
  int i;
  CreatSqList(&L);
  Qsort(L, 1, L.Length);
  for (i = 1; i <= L.Length; i++)
    printf("%d ", L.elem[i]);
  return 0;
}
void Qsort(SqList L, int low, int high) {
  int pivotloc;
  if (low < high) {
    pivotloc = Partition(L, low, high);
    Qsort(L, low, pivotloc - 1);
    Qsort(L, pivotloc + 1, high);
  }
}
/*你的代码将被嵌在这里 */
void CreatSqList(SqList *L) {
  int n;
  scanf("%d", &n);
  L->Length = n, L->elem = (int *)malloc(sizeof(int) * (n + 1));
  for (int i = 1; i <= n; i++)
    scanf("%d", L->elem + i);
}

int Partition(SqList L, int low, int high) {
  L.elem[0] = L.elem[low];
  while (low < high) {
    while (high > low && L.elem[0] <= L.elem[high])
      --high;
    if (high > low)
      L.elem[low] = L.elem[high];
    while (low < high && L.elem[0] >= L.elem[low])
      ++low;
    if (low < high)
      L.elem[high] = L.elem[low];
  }
  L.elem[low] = L.elem[0];
  return low;
}

// #include <time.h>
// int Partition(SqList L, int low, int high) {
//   if (low >= high)
//     return low + 2;
//   srand(time(NULL));
//   L.elem[0] = L.elem[rand() % (high - low + 1) + low];
//   int i = low, j = high;
//   while (1) {
//     while (L.elem[i] < L.elem[0])
//       ++i;
//     while (L.elem[j] > L.elem[0])
//       --j;
//     if (i >= j)
//       break;
//     int tmp = L.elem[i];
//     L.elem[i] = L.elem[j], L.elem[j] = tmp;
//     ++i, --j;
//   }
//   Partition(L, low, i - 1);
//   Partition(L, j + 1, high);
//   return low + 2;
// }
/*
Sample Input:
10
5 2 4 1 8 9 10 12 3 6
Sample Output:
1 2 3 4 5 6 8 9 10 12
HINT
*/
