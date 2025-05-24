
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode {
  ElemType data;
  struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTree Create(); /* 细节在此不表 */
void PrintNode(BiTree T);
int n; // 要打印的结点的在后序序列中的序号
int main() {
  BiTree T = Create();
  scanf("%d", &n);
  printf("The %d-th node in postorder is: ", n);
  PrintNode(T);
  printf("\n");
  return 0;
}
/* 你的代码将被嵌在这里 */
void PrintNode(BiTree T) {
  static int i = 0;
  if (!T)
    return;
  PrintNode(T->lchild);
  PrintNode(T->rchild);
  if (++i == n) {
    printf("%c", T->data);
    return;
  }
}