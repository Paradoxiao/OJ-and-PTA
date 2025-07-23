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

// 函数声明
#include <algorithm>
Status ListInsert_SortedSq(SqList &L, ElemType e) {
  if (L.size == L.capacity)
    L.base = (ElemType *)realloc(L.base, sizeof(ElemType) * ++L.capacity);
  L.base[L.size++] = e;
  std::sort(L.base, L.base + L.size);
  return OK;
}

// 顺序表初始化函数
Status InitList_Sq(SqList &L) {
  // 开辟一段空间
  L.base = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
  // 检测开辟是否成功
  if (!L.base) {
    exit(OVERFLOW);
  }
  // 赋值
  L.size = 0;
  L.capacity = LIST_INIT_SIZE;

  return OK;
}

// 顺序表输出函数
void ListPrint_Sq(SqList L) {
  ElemType *p = L.base; // 遍历元素用的指针

  for (int i = 0; i < L.size; ++i) {
    if (i == L.size - 1) {
      printf("%d", *(p + i));
    } else {
      printf("%d ", *(p + i));
    }
  }
}
int main() {
  // 声明一个顺序表
  SqList L;
  // 初始化顺序表
  InitList_Sq(L);

  int number = 0;
  ElemType e;

  scanf("%d", &number); // 插入数据的个数

  for (int i = 0; i < number; ++i) {
    scanf("%d", &e); // 输入数据
    ListInsert_SortedSq(L, e);
  }

  ListPrint_Sq(L);

  return 0;
}

/* 请在这里填写答案 */