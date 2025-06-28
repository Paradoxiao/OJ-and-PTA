#include <cstdio>
using namespace std;
typedef int KeyType; // 定义关键字类型
typedef struct node  // 记录类型
{
  KeyType key;                  // 关键字项
  struct node *lchild, *rchild; // 左右孩子指针
} BSTNode;

int ReadData(int a[]);                  // 键盘输入若干个整数，顺序保存在数组a中，并返回输入整数的数量。由裁判程序实现，细节不表。
BSTNode *CreatBST(KeyType A[], int n);  // 顺序读入数组A中的关键字, 依序建立一棵二叉排序树并返回根结点指针.
int DeleteBST(BSTNode *&bt, KeyType k); // 在bt中删除关键字为k的节点. 找到关键字k并删除返回1，否则返回0。
int SearchBST(BSTNode *bt, KeyType k);  // 输出从根节点到查找到的节点的路径 ,如果找到k,返回1，否则返回0。提示：输出语句格式如：printf("%d ",bt->key);
void InorderTraversal(BSTNode *bt);     // 中序遍历并输出该二叉排序树。由裁判程序实现，输出语句格式如：printf("%d ",bt->key);
void PreorderTraversal(BSTNode *bt);    // 先序遍历并输出该二叉排序树。由裁判程序实现，输出语句格式如：printf("%d ",bt->key);

int main() {
  BSTNode *bt = NULL;
  KeyType k, X;
  int a[100] = {4, 9, 0, 1, 8, 6, 3, 5, 2, 7};
  // N = ReadData(a);     // 键盘读入N个整数，顺序保存在数组a中. 裁判程序实现，细节不表。
  bt = CreatBST(a, 10); // 根据数组a,创建一棵BST树
  // printf("Preorder: ");
  // PreorderTraversal(bt);
  // printf("\n");    // 先序遍历并输出该二叉排序树。
  // scanf("%d", &k); // 输入待查找的关键字k
  // SearchBST(bt, k);
  // printf("\n");     // 查找k，并输出从根节点到查找到的节点的路径 ,如果找到k,返回1，否则返回0
  // scanf("%d", &k);  // 输入待删除的关键字k
  // DeleteBST(bt, k); // 在二叉排序树中删除关键字为k的结点。
  // printf("Inorder: ");
  // InorderTraversal(bt);
  // printf("\n"); // 中序遍历并输出该二叉排序树。
  return 0;
}

/* 请在这里填写答案 */
BSTNode *CreatBST(KeyType A[], int n) {
  BSTNode *T = new BSTNode{*A, nullptr, nullptr}, *p, *q, *t;
  for (int i = 1; i < n; i++) {
    p = T, q = T, t = new BSTNode{A[i], nullptr, nullptr};
    while (p)
      if (A[i] < p->key)
        q = p, p = p->lchild;
      else if (A[i] > p->key)
        q = p, p = p->rchild;
    if (A[i] > q->key)
      q->rchild = t;
    if (A[i] < q->key)
      q->lchild = t;
  }
  return T;
}
int DeleteBST(BSTNode *&bt, KeyType k) {
  if (!bt)
    return 0;
  if (k < bt->key)
    return DeleteBST(bt->lchild, k);
  if (k > bt->key)
    return DeleteBST(bt->rchild, k);

  if (!bt->lchild && !bt->rchild) {
    bt = nullptr;
    return 1;
  }
  if (!bt->rchild) {
    bt = bt->lchild;
    return 1;
  }
  if (!bt->lchild) {
    bt = bt->rchild;
    return 1;
  }
  BSTNode *p = bt->rchild, *pp = nullptr;
  while (p->lchild)
    pp = p, p = p->lchild;
  bt->key = p->key;
  if (pp) {
    if (pp->lchild->rchild)
      pp->lchild = pp->lchild->rchild;
    else
      pp->lchild = nullptr;
  }
  return 1;
}
int SearchBST(BSTNode *bt, KeyType k) {
  while (bt && k > bt->key) {
    printf("%d ", bt->key);
    bt = bt->rchild;
  }
  while (bt && k < bt->key) {
    printf("%d ", bt->key);
    bt = bt->lchild;
  }
  printf("%d ", k);
  return bt != nullptr;
}
