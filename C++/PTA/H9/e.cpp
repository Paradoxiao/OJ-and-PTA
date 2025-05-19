#include <iostream>
#include <string>
using namespace std;
struct BiTNode {
  char data;
  BiTNode *lchild, *rchild;
};
int PreOrder(BiTNode *T);
BiTNode *CreateBiTree(string &s);
int main() {
  string s;
  while (cin >> s) {
    BiTNode *root = CreateBiTree(s);
    cout << "num: " << PreOrder(root);
    cout << endl;
  }
  return 0;
}
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
int PreOrder(BiTNode *T) {
  if (!T)
    return 0;
  return (T->lchild && !T->rchild || !T->lchild && T->rchild ? 1 : 0) +
         PreOrder(T->lchild) + PreOrder(T->rchild);
}