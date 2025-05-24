
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode {
  ElemType data;
  struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTree Create(); /* 细节在此不表 */

int NodeCount(BiTree T) {
  if (!T)
    return 0;
  return (T->lchild && T->rchild ? 1 : 0) + NodeCount(T->lchild) +
         NodeCount(T->rchild);
}

int main() {
  BiTree T = Create();

  printf("%d\n", NodeCount(T));
  return 0;
}
/* 你的代码将被嵌在这里 */