#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 1000
using namespace std;
typedef int ElemType;
typedef struct {
  ElemType *r;
  int length;
} SqList;

void Create_Sq(SqList &L); // 建立待排序列，实现细节隐藏
void Merge(SqList L, int low, int m, int high);

void MSort(SqList L, int low, int high) { /*用分治法进行二路归并排序*/
  int mid;
  if (low < high) {           /*区间长度大于1*/
    mid = (low + high) / 2;   /*分解*/
    MSort(L, low, mid);       /*递归地对low到mid序列排序 */
    MSort(L, mid + 1, high);  /*递归地对mid+1到high序列排序 */
    Merge(L, low, mid, high); /*归并*/
  }
}

int main() {
  SqList L;
  int i;
  L.r = new ElemType[MAXSIZE + 1];
  L.length = 0;
  Create_Sq(L);
  MSort(L, 1, L.length);
  for (i = 1; i <= L.length; i++)
    if (i == 1)
      cout << L.r[i];
    else
      cout << " " << L.r[i];

  return 0;
}
/* 请在这里填写答案 */
void Merge(SqList L, int low, int m, int high) {
  int *c = new int[high - low + 1];
  int *i = L.r + low, *j = L.r + m + 1, *k = c;
  while (i <= L.r + m && j <= L.r + high)
    if (*i < *j)
      *(k++) = *(i++);
    else
      *(k++) = *(j++);
  while (i <= L.r + m)
    *(k++) = *(i++);
  while (j <= L.r + high)
    *(k++) = *(j++);
  copy(c, k, L.r + low);
  delete[] c;
}
