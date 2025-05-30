#include <cstdio>
using namespace std;
struct node {
  int data;
  node *firstChild, *nextSibling;
};
using CSTree = node *;
void create(CSTree &t) {
  int n;
  scanf("%d", &n);
  if (n == 0) {
    t = nullptr;
    return;
  }
  t = new node;
  create(t->firstChild);
  create(t->nextSibling);
}
int LeafCountOfCSTree(CSTree CST) {
  int n, leafCountOfFirstTree, leafCountOfSubForest;
  if (!CST)
    n = 0;
  else {
    if (!CST->firstChild)
      leafCountOfFirstTree = 1;
    else
      leafCountOfFirstTree = LeafCountOfCSTree(CST->firstChild);
    leafCountOfSubForest = LeafCountOfCSTree(CST->nextSibling);
    n = leafCountOfFirstTree + leafCountOfSubForest;
  }
  return n;
}
int main() {
  node *t;
  create(t);
  printf("该森林叶子结点数为%d!\n\n该森林叶子结点数为%d!\n", LeafCountOfCSTree(t), LeafCountOfCSTree(t));
  return 0;
}