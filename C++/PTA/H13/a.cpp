using TElemType = int;
// 森林的孩子兄弟表示法存储结构定义
typedef struct CSNode {
  TElemType data;
  struct CSNode *firstchild;
  struct CSNode *nextsibling;
} CSNode, *CSTree;
// 递归与分治计算森林或者树的叶子数
int TreeorForestLeafCout(CSTree F) {
  int n, leafNumberOfFirstTree, leafNumberOfSubForest;
  if (!F)
    n = 0;
  else {
    if (!F->firstchild)
      leafNumberOfFirstTree = 1 // 如果是叶子节点
          ;
    else
      leafNumberOfFirstTree = TreeorForestLeafCout(F->firstchild) // 递归计算第一个树的叶子数
          ;
    leafNumberOfSubForest = TreeorForestLeafCout(F->nextsibling) // 递归计算子森林的叶子数
        ;
    n = leafNumberOfFirstTree + leafNumberOfSubForest;
  }
  return n;
}