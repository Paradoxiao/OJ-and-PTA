#include <iostream>
#include <string>
using namespace std;

struct BiTNode {
  char data;
  BiTNode *lchild, *rchild;
};

void PreOrder(BiTNode *T);        // 先序遍历
BiTNode *CreateBiTree(string &s); // 创建二叉树，s存放带虚结点的先序遍历序列

int main() {
  string s;
  while (cin >> s) {
    BiTNode *root = CreateBiTree(s);
    PreOrder(root);
    cout << endl;
  }
  return 0;
}

// 请在此处填写答案

// 按字符串s创建二叉树，返回根结点指针
BiTNode *CreateBiTree(string &s) {
  if (s[0] == '*') {
    s = s.substr(1);
    return NULL;
  }
  BiTNode *p = new BiTNode;
  p->data = s[0];
  s = s.substr(1);
  p->lchild = CreateBiTree(s);
  p->rchild = CreateBiTree(s);
  return p;
}
void PreOrder(BiTNode *T) {
  cout << T->data;
  if (T->lchild)
    PreOrder(T->lchild);
  if (T->rchild)
    PreOrder(T->rchild);
} // 先序遍历
