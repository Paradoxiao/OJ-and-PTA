#include <algorithm>
#include <iostream>
using namespace std;
using KeyType = int;
struct SqList {
  KeyType *elem; /*elem[0]一般作哨兵或缓冲区*/
  int Length;
};
void CreatSqList(SqList *L);
void ShellInsert(SqList L, int dk);
void ShellSort(SqList L);

int main() {
  SqList L;
  int i;
  CreatSqList(&L);
  ShellSort(L);
  return 0;
}
void CreatSqList(SqList *L) {
  L->Length = 9;
  int a[] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  L->elem = new int[10];
  copy(a, a + 10, L->elem);
}
void ShellSort(SqList L) {
  /*按增量序列dlta[0…t-1]对顺序表L作Shell排序,假设规定增量序列为7,3,1*/
  int k;
  int dlta[3] = {7, 3, 1};
  int t = 3;
  for (k = 0; k < t; ++k) {
    ShellInsert(L, dlta[k]);
    for (int i = 1; i <= L.Length; i++)
      cout << L.elem[i] << " ";
    cout << endl;
  }
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
