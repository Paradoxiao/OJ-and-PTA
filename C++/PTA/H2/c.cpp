
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode {
  ElemType data;
  struct LNode *next;
} LNode, *LinkList;

LinkList Create() {
  LinkList head = new LNode, now = head;
  head->next = nullptr;
  int n;
  std::cin >> n;
  while (n != -1) {
    now->next = new LNode;
    now = now->next;
    now->data = n;
    std::cin >> n;
  }
  now->next = nullptr;
  return head;
} /* 细节在此不表 */

int Length(LinkList L) {
  int i = 0;
  while (L->next) {
    L = L->next;
    i++;
  }
  return i;
}

int main() {
  LinkList L = Create();
  printf("%d\n", Length(L));
  // while (L->next) {
  //   L = L->next;
  //   std::cout << L->data << " ";
  // }
  return 0;
}

/* 你的代码将被嵌在这里 */