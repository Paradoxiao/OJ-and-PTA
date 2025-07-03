#include <stdio.h>
#include <stdlib.h>
typedef int KeyType;
typedef struct {
  KeyType *elem; /*elem[0]一般作哨兵或缓冲区*/
  int Length;
} SqList;
void CreatSqList(SqList *L); /*待排序列建立，由裁判实现，细节不表*/
void ShellInsert(SqList L, int dk);
void ShellSort(SqList L);

int main() {
  SqList L;
  int i;
  CreatSqList(&L);
  ShellSort(L);
  for (i = 1; i <= L.Length; i++) {
    printf("%d ", L.elem[i]);
  }
  return 0;
}
void ShellSort(SqList L) {
  /*按增量序列dlta[0…t-1]对顺序表L作Shell排序,假设规定增量序列为5,3,1*/
  int k;
  int dlta[3] = {5, 3, 1};
  int t = 3;
  for (k = 0; k < t; ++k)
    ShellInsert(L, dlta[k]);
}
/*你的代码将被嵌在这里 */
void ShellInsert(SqList L, int dk) {
  for (int i = 1 + dk; i <= L.Length; i++) {
    L.elem[0] = L.elem[i];
    int j = i - dk;
    while (L.elem[j] > L.elem[0] && j > 0)
      L.elem[j + dk] = L.elem[j], j -= dk;
    L.elem[j + dk] = L.elem[0];
  }
}
