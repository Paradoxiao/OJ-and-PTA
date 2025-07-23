#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode {
  ElemType data;
  struct LNode *next;
} LNode, *LinkList;

LinkList Create() {
  LinkList a = (LNode *)malloc(sizeof(LNode)), temp = a;
  int n;
  scanf("%d", &n);
  while (n != -1) {
    temp->next = (LNode *)malloc(sizeof(LNode));
    temp = temp->next;
    temp->data = n;
    scanf("%d", &n);
  }
  temp->next = nullptr;
  return a;
} /* 细节在此不表 */
void print(LinkList L);
int insert_link(LinkList L, int i, ElemType e) {
  if (i < 1)
    return 0;
  int count = 0;
  LNode *pre = L;
  while (pre && count < i - 1) {
    pre = pre->next;
    count++;
  }
  if (!pre)
    return 0;
  LNode *newNode = (LNode *)malloc(sizeof(LNode));
  newNode->next = pre->next;
  pre->next = newNode;
  newNode->data = e;
  return 1;
}

int main() {
  int position, insert_data;
  int flag;
  LinkList L = Create();
  scanf("%d", &position);
  scanf("%d", &insert_data);
  flag = insert_link(L, position, insert_data);
  if (flag) {
    print(L);
  } else {
    printf("Wrong Position for Insertion");
  }
  return 0;
}
void print(LinkList L) {
  LinkList p;
  p = L->next;
  while (p) {
    printf("%d ", p->data);
    p = p->next;
  }
}
/* 请在这里填写答案 */