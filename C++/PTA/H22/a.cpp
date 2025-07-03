#include <stdio.h>
#include <stdlib.h>
typedef int KeyType;
typedef struct {
  KeyType *elem; /*elem[0]一般作哨兵或缓冲区*/
  int Length;
} SqList;
void CreatSqList(SqList *L); /*待排序列建立，由裁判实现，细节不表*/
void InsertSort(SqList L);
int main() {
  SqList L;
  int i;
  CreatSqList(&L);
  InsertSort(L);
  for (i = 1; i <= L.Length; i++) {
    printf("%d ", L.elem[i]);
  }
  return 0;
}
/*你的代码将被嵌在这里 */
void InsertSort(SqList L) {
  for (int i = 2; i <= L.Length; i++) {
    L.elem[0] = L.elem[i];
    int j = i - 1;
    while (L.elem[j] > L.elem[0])
      L.elem[j + 1] = L.elem[j], j--;
    L.elem[j + 1] = L.elem[0];
  }
}
