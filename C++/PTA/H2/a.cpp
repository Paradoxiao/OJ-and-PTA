
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
Status ListInsert_Sq(SqList &L, int pos, ElemType e) {
  if (pos < 1 || pos > L.size + 1)
    return ERROR;
  if (L.size == L.capacity)
    L.base = (int *)realloc(L.base, sizeof(ElemType) * L.capacity++);
  for (int i = ++L.size; i > pos; i--)
    L.base[i] = L.base[i - 1];
  L.base[pos] = e;
  return OK;
}
Status ListDelete_Sq(SqList &L, int pos, ElemType &e) {
  if (pos < 1 || pos > L.size)
    return ERROR;
  e = L.base[pos];
  L.size--;
  for (int i = pos; i <= L.size; i++)
    L.base[i] = L.base[i + 1];
  return OK;
}
int ListLocate_Sq(SqList L, ElemType e) {
  for (int i = 1; i <= L.size; i++)
    if (L.base[i] == e)
      return i;
  return 0;
}
void ListPrint_Sq(SqList L) {
  for (int i = 1; i <= L.size; ++i)
    printf(i == 1 ? "%d" : " %d", L.base[i]);
}

// 结构初始化与销毁操作
Status InitList_Sq(SqList &L) {
  // 初始化L为一个空的有序顺序表
  L.base = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
  if (!L.base)
    exit(OVERFLOW);
  L.capacity = LIST_INIT_SIZE;
  L.size = 0;
  return OK;
}

int main() {
  SqList L;

  if (InitList_Sq(L) != OK) {
    printf("InitList_Sq: 初始化失败！！！\n");
    return -1;
  }

  for (int i = 1; i <= 10; ++i)
    ListInsert_Sq(L, i, i);
  int operationNumber; // 操作次数
  scanf("%d", &operationNumber);

  while (operationNumber != 0) {
    int operationType; // 操作种类
    scanf("%d", &operationType);

    if (operationType == 1) { // 增加操作
      int pos;
      ElemType elem;
      scanf("%d%d", &pos, &elem);
      ListInsert_Sq(L, pos, elem);
    } else if (operationType == 2) { // 删除操作
      int pos;
      ElemType elem;
      scanf("%d", &pos);
      ListDelete_Sq(L, pos, elem);
      printf("%d\n", elem);
    } else if (operationType == 3) { // 查找定位操作
      ElemType elem;
      scanf("%d", &elem);
      int pos = ListLocate_Sq(L, elem);
      if (pos >= 1 && pos <= L.size)
        printf("%d\n", pos);
      else
        printf("NOT FIND!\n");
    } else if (operationType == 4) { // 输出操作
      ListPrint_Sq(L);
    }
    operationNumber--;
  }
  return 0;
}

/* 请在这里填写答案 */