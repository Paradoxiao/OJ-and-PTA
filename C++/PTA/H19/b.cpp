#include <stdio.h>
#include <stdlib.h>

// typedef enum { false, true } bool;
typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
  ElementType Data;
  BinTree Left;
  BinTree Right;
};

BinTree BuildTree(); /* 由裁判实现，细节不表 */
bool IsBST(BinTree T);

int main() {
  BinTree T;

  T = BuildTree();
  if (IsBST(T))
    printf("Yes\n");
  else
    printf("No\n");

  return 0;
}
/* 你的代码将被嵌在这里 */
bool IsBST(BinTree T) {
  if (T == NULL || (T->Left == NULL && T->Right == NULL))
    return true;
  BinTree left = T->Left, right = T->Right;
  if (left) {
    while (left->Right != NULL)
      left = left->Right;
    if (T->Data <= left->Data)
      return false;
  }
  if (right) {
    while (right->Left != NULL)
      right = right->Left;
    if (T->Data >= right->Data)
      return false;
  }
  return (!T->Left || IsBST(T->Left)) && (!T->Right || IsBST(T->Right));
}
