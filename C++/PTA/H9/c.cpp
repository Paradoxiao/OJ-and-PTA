
// 头文件包含
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

// 函数状态码定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define INFEASIBLE -2
#define NULL 0
typedef int Status;

// 二叉链表存储结构定义
typedef int TElemType;
typedef struct BiTNode {
  TElemType data;
  struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 先序创建二叉树各结点，输入0代表创建空树。
Status CreateBiTree(BiTree &T) {
  TElemType e;
  scanf("%d", &e);
  if (e == 0)
    T = NULL;
  else {
    T = (BiTree)malloc(sizeof(BiTNode));
    if (!T)
      exit(OVERFLOW);
    T->data = e;
    CreateBiTree(T->lchild);
    CreateBiTree(T->rchild);
  }
  return OK;
}

// 下面是需要实现的函数的声明
int XNodeCountOfBiTree(BiTree T, TElemType x) {
  if (!T)
    return 0;
  return (T->data == x ? 1 : 0) + XNodeCountOfBiTree(T->lchild, x) +
         XNodeCountOfBiTree(T->rchild, x);
}
// 下面是主函数
int main() {
  BiTree T;
  int n;
  TElemType x;
  CreateBiTree(T); // 先序递归创建二叉树
  scanf("%d", &x);
  n = XNodeCountOfBiTree(T, x);
  printf("%d", n);
  return 0;
}

/* 请在这里填写答案 */