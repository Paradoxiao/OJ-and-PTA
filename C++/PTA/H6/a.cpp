#include <cstdlib>
#include <iostream>
using namespace std;

typedef int Status;
typedef int ElemType;

typedef struct DuLNode {
  ElemType data;
  struct DuLNode *prior;
  struct DuLNode *next;
} DuLNode, *DuLinkList;

DuLinkList GetElemP_DuL(DuLinkList L, int i) {
  int j;
  DuLinkList p;
  p = L->next;
  j = 1;
  while (j < i && p != L) {
    p = p->next;
    ++j;
  }
  if (p == L || j > i)
    return NULL;
  return p;
}

Status ListInsert_DuL(DuLinkList &L, int i, ElemType e) {
  if (i < 1)
    return 0;
  DuLNode *p;
  for (p = L->next; p != L && i - 1; p = p->next, i--)
    ;
  if (p == L->next)
    return 0;
  DuLNode *newNode = (DuLNode *)malloc(sizeof(DuLNode));
  newNode->data = e;
  p->prior->next = newNode;
  newNode->prior = p->prior;
  newNode->next = p;
  p->prior = newNode;
  return 1;
}
void CreateDuList(DuLinkList &L, int n) {
  L = new DuLNode;
  L->next = L->prior = L;
  DuLNode *p = L;
  for (int i = 0; i < n; i++) {
    p->next = new DuLNode;
    cin >> p->next->data;
    p->next->prior = p;
    p = p->next;
  }
  p->next = L;
  return;
} // 建立循环双链表，实现细节隐藏
void print(DuLinkList &L) {
  DuLinkList p;
  int flag = 1;
  p = L->next;
  while (p != L) {
    if (flag)
      cout << p->data;
    else
      cout << " " << p->data;
    flag = 0;
    p = p->next;
  }
}

int main() {
  int a;
  ElemType e;
  int n;
  DuLinkList L;
  cin >> n;
  CreateDuList(L, n);
  cin >> a >> e;
  ListInsert_DuL(L, a, e);
  print(L);
  return 0;
}
/* 请在这里填写答案 */