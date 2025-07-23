
// 库函数头文件包含
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

// 函数状态码定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define NULL 0

typedef int Status;
typedef int ElemType; // 假设线性表中的元素均为整型

typedef struct LNode {
  ElemType data;
  struct LNode *next;
} LNode, *LinkList;

// 链表创建函数
Status ListCreate_L(LinkList &L, int n) {
  LNode *rearPtr, *curPtr;
  L = (LNode *)malloc(sizeof(LNode));
  if (!L)
    exit(OVERFLOW);
  L->next = NULL;
  rearPtr = L;
  for (int i = 1; i <= n; i++) {
    curPtr = (LNode *)malloc(sizeof(LNode));
    if (!curPtr)
      exit(OVERFLOW);
    scanf("%d", &curPtr->data);
    curPtr->next = NULL;
    rearPtr->next = curPtr;
    rearPtr = curPtr;
  }
  return OK;
}
// 链表输出函数
void ListPrint_L(LinkList L) {
  LNode *p = L->next;
  if (!p) {
    printf("空表");
    return;
  }
  while (p != NULL) {
    if (p->next != NULL)
      printf("%d ", p->data);
    else
      printf("%d", p->data);
    p = p->next;
  }
}
// 下面是需要实现的函数的声明
void ListLocateAndDel_L(LinkList L, ElemType x) {
  LNode *temp = nullptr;
  while (L->next) {
    if (L->next->data == x)
      temp = L;
    L = L->next;
  }
  if (!temp)
    return;
  if (!temp->next->next) {
    temp->next = nullptr;
    return;
  }
  temp->next = temp->next->next;
}

int main() {
  LinkList L;
  int n;
  int x;
  scanf("%d", &n); // 输入链表中元素个数
  if (ListCreate_L(L, n) != OK) {
    printf("表创建失败！！！\n");
    return -1;
  }
  scanf("%d", &x); // 输入待查找元素
  ListLocateAndDel_L(L, x);
  ListPrint_L(L);
  return 0;
}

/* 请在这里填写答案 */