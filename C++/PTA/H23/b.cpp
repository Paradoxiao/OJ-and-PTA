#include <stdio.h>
#include <stdlib.h>
typedef int KeyType;
typedef struct {
  KeyType *elem; /*elem[0]一般作哨兵或缓冲区*/
  int Length;
} SqList;
typedef SqList HeapType;
void CreatSqList(HeapType *L); /*待排序列建立，由裁判实现，细节不表*/
void HeapAdjust(HeapType H, int s, int m);
void HeapSort(HeapType H);
int main() {
  HeapType L;
  int i;
  CreatSqList(&L);
  HeapSort(L);
  for (i = 1; i <= L.Length; i++) {
    printf("%d ", L.elem[i]);
  }
  return 0;
}
void HeapSort(HeapType H) { /*堆顺序表H进行堆排序*/
  int i;
  KeyType rc;
  /*建立初始堆*/
  for (i = H.Length / 2; i > 0; i--) {
    HeapAdjust(H, i, H.Length);
  }
  for (i = H.Length; i > 1; i--) {
    rc = H.elem[1];
    H.elem[1] = H.elem[i];
    H.elem[i] = rc;
    HeapAdjust(H, 1, i - 1);
  }
}
/*你的代码将被嵌在这里 */
void HeapAdjust(HeapType H, int s, int m) {
  int p = s;
  while (p * 2 <= m) {
    int l = p * 2, r = p * 2 + 1, big;
    if (r <= m && H.elem[r] > H.elem[l])
      big = r;
    else
      big = l;
    if (H.elem[p] >= H.elem[big])
      break;
    int tmp = H.elem[p];
    H.elem[p] = H.elem[big], H.elem[big] = tmp;
    p = big;
  }
}
