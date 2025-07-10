#include <iostream>
#define MAXNUM_KEY 8 // 关键字项数的最大值
#define RADIX 10     // 关键字基数，此时是十进制整数的基数
#define MAX_SPACE 10000
using namespace std;

typedef struct {
  char keys[MAXNUM_KEY]; // 关键字
  int next;
} SLCell; // 静态链表的结点类型
typedef struct {
  SLCell r[MAX_SPACE]; // 静态链表的可利用空间，r[0]为头结点
  int keynum;          // 记录的当前关键字个数
  int recnum;          // 静态链表的当前长度
} SLList;              // 静态链表类型

void InitList(SLList *L) {
  int i, n, keynum;
  cin >> n >> keynum;
  (*L).keynum = keynum;
  (*L).recnum = n;
  for (i = 1; i <= n; i++)
    cin >> (*L).r[i].keys;
}

void Distribute(SLCell *r, int i, int *f, int *e);
// 静态链表L的r域中记录已按（keys[0], …, keys[i-1]）有序
// 该函数按第i个关键字keys[i]建立RADIX个子表，使同一子表中记录的keys[i]相同。
// f[0..RADIX-1]和e[0..RADIX-1]分别指向各子表中第一个和最后一个记录

void Collect(SLCell *r, int i, int *f, int *e);
// 该函数按keys[i]自小至大地将f[0..RADIX-1]所指各子表依次链接成一个链表
// e[0..RADIX-1]为各子表的尾指针

void RadixSort(SLList &L) {
  int i;
  int f[RADIX], e[RADIX];
  for (i = 0; i < L.recnum; ++i)
    L.r[i].next = i + 1;
  L.r[L.recnum].next = 0; // 将L改造为静态链表
  for (i = L.keynum - 1; i >= 0; i--) {
    Distribute(L.r, i, f, e); // 第i趟分配
    Collect(L.r, i, f, e);    // 第i趟收集
  }
}

void print(SLList L) {
  int p, flag = 1;
  for (p = L.r[0].next; p; p = L.r[p].next) {
    if (flag) {
      cout << L.r[p].keys;
      flag = 0;
    } else
      cout << " " << L.r[p].keys;
  }
}

int main() {
  SLList l;
  InitList(&l);
  RadixSort(l);
  print(l);
  return 0;
}
/* 请在这里填写答案 */
void Distribute(SLCell *r, int i, int *f, int *e) {
  for (int i = 0; i < RADIX; i++)
    f[i] = 0, e[i] = 0;
  int p = r->next;
  while (p) {
    int k = r[p].keys[i] - '0';
    if (!f[k])
      f[k] = p;
    else
      r[e[k]].next = p;
    e[k] = p, p = r[p].next;
  }
}
void Collect(SLCell *r, int i, int *f, int *e) {
  int begin = 0, end = 0;
  for (int j = 0; j < RADIX; j++)
    if (f[j]) {
      begin = f[j];
      break;
    }
  for (int j = 0; j < RADIX; j++)
    if (f[j]) {
      if (end)
        r[end].next = f[j];
      end = e[j];
    }
  if (end)
    r[end].next = 0;
  r->next = begin;
}

/*
Sample Input:
10 3
278 109 063 930 589 184 505 269 008 083
Sample Output:
008 063 083 109 184 269 278 505 589 930
HINT:
*/
