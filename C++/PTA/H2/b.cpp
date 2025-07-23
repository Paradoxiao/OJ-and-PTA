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

typedef int Status;

// 顺序表的存储结构定义
#define LIST_INIT_SIZE 100
typedef int ElemType; // 假设线性表中的元素均为整型
typedef struct {
  ElemType *base; // 存储空间基地址
  int size;       // 表中元素的个数
  int capacity;   // 表容量大小
} SqList;         // 顺序表类型定义

Status ListCreate_Sq(SqList &L) {
  int n;
  scanf("%d", &n);
  L.size = n;
  L.capacity = LIST_INIT_SIZE;
  L.base = new ElemType[LIST_INIT_SIZE];
  if (!L.base)
    return ERROR;
  for (int i = 0; i < n; i++)
    scanf("%d", L.base + i);
  return OK;
}
void ListReverse_Sq(SqList &L) {
  ElemType *head = L.base, *tail = L.base + L.size - 1;
  while (tail != head && tail != head + 1) {
    ElemType temp = *head;
    *head = *tail;
    *tail = temp;
    head++;
    tail--;
  }
}

int main() {
  SqList L;
  ElemType *p;

  if (ListCreate_Sq(L) != OK) {
    printf("ListCreate_Sq: 创建失败！！！\n");
    return -1;
  }

  ListReverse_Sq(L);

  if (L.size) {
    for (p = L.base; p < L.base + L.size - 1; ++p) {
      printf("%d ", *p);
    }
    printf("%d", *p);
  }
  return 0;
}
/* 请在这里填写答案 */