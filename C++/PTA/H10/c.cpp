#include <cstddef>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
// typedef enum { false, true } bool;

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
  ElementType Data;
  BinTree Left;
  BinTree Right;
  int flag;
};

/*------堆栈的定义-------*/
typedef Position SElementType;
typedef struct SNode *PtrToSNode;
struct SNode {
  SElementType Data;
  PtrToSNode Next;
};
typedef PtrToSNode Stack;

/* 裁判实现，细节不表 */
Stack CreateStack() {
  SNode *stack = new SNode;
  stack->Next = nullptr;
  return stack;
}
bool IsEmpty(Stack S) {
  return S->Next == nullptr;
}
bool Push(Stack S, SElementType X) {
  SNode *newnode = (SNode *)malloc(sizeof(SNode));
  newnode->Next = S->Next;
  newnode->Data = X;
  S->Next = newnode;
  return 1;
}
SElementType Pop(Stack S) {
  SElementType temp = S->Next->Data;
  S->Next = S->Next->Next;
  return temp;
} /* 删除并仅返回S的栈顶元素 */
SElementType Peek(Stack S) {
  return S->Next->Data;
} /* 仅返回S的栈顶元素 */
/*----堆栈的定义结束-----*/

BinTree CreateBinTree() {
  // 直接嵌套生成树结构
  // A
  // ├─B
  // │ ├─D
  // │ └─F
  // │   └─E
  // └─C
  //   ├─G
  //   │ └─H
  //   └─I
  BinTree tree = new TNode{'A', nullptr, nullptr, 0};
  tree->Left = new TNode{'B', nullptr, nullptr, 0};
  tree->Left->Left = new TNode{'D', nullptr, nullptr, 0};
  tree->Left->Right = new TNode{'F', nullptr, nullptr, 0};
  tree->Left->Right->Left = new TNode{'E', nullptr, nullptr, 0};
  tree->Right = new TNode{'C', nullptr, nullptr, 0};
  tree->Right->Left = new TNode{'G', nullptr, nullptr, 0};
  tree->Right->Left->Right = new TNode{'H', nullptr, nullptr, 0};
  tree->Right->Right = new TNode{'I', nullptr, nullptr, 0};
  return tree;
} /* 裁判实现，细节不表 */
void InorderTraversal(BinTree BT) {
  if (BT == NULL)
    return;
  Stack S = CreateStack();
  BinTree T = BT;
  while (T || !IsEmpty(S)) {
    while (T) {
      Push(S, T);
      T = T->Left;
    }
    if (!IsEmpty(S)) {
      T = Pop(S);
      printf(" %c", T->Data);
    }
    T = T->Right;
  }
}
void PreorderTraversal(BinTree BT) {
  if (BT == NULL)
    return;
  Stack S = CreateStack();
  BinTree T = BT;
  Push(S, T);
  while (!IsEmpty(S)) {
    T = Pop(S);
    printf(" %c", T->Data);
    if (T->Right)
      Push(S, T->Right);
    if (T->Left)
      Push(S, T->Left);
  }
}
void PostorderTraversal(BinTree BT) {
  if (BT == NULL)
    return;
  Stack S = CreateStack();
  Push(S, BT);
  while (!IsEmpty(S)) {
    BinTree T = Peek(S);
    if (!T->flag) {
      T->flag = 1;
      if (T->Right)
        Push(S, T->Right);
      if (T->Left)
        Push(S, T->Left);
      continue;
    }
    Pop(S);
    printf(" %c", T->Data);
    T->flag = 0;
  }
}

int main() {
  BinTree BT = CreateBinTree();
  printf("Inorder:");
  InorderTraversal(BT);
  printf("\n");
  printf("Preorder:");
  PreorderTraversal(BT);
  printf("\n");
  printf("Postorder:");
  PostorderTraversal(BT);
  printf("\n");
  return 0;
}
/* 你的代码将被嵌在这里 */