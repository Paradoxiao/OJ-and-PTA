// 头文件包含
#include <iostream>
#include <malloc.h>
#include <stdio.h>
using namespace std;

// 函数状态码定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define INFEASIBLE -2
#define NULL 0
typedef int Status;

char s[31];
int cnt = 0;

// 树和森林的孩子兄弟法存储结构定义
typedef char TElemType;
typedef struct CSNode {
  TElemType data;
  struct CSNode *firstChild;
  struct CSNode *nextSibling;
} CSTNode, *CSTree;

Status CreateCSTree(CSTree &CST) {
  TElemType e;
  e = s[cnt++];
  if (e == '*')
    CST = NULL;
  else {
    CST = (CSTNode *)malloc(sizeof(CSTNode));
    if (!CST)
      exit(OVERFLOW);
    CST->data = e;
    CreateCSTree(CST->firstChild);
    CreateCSTree(CST->nextSibling);
  }
  return OK;
}

// 下面是需要实现的函数的声明
int LeafCountOfCSTree(CSTree CST);
// 下面是主函数
int main() {
  CSTree CST;
  while (cin >> s) {
    CreateCSTree(CST);
    cout << LeafCountOfCSTree(CST);
    cout << endl;
    cnt = 0;
  }
  return 0;
}
/* 请在这里填写答案 */
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