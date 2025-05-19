#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct QNode {
  ElemType data;
  struct QNode *next;
} QNode;

typedef struct {
  QNode *front;
  QNode *rear;
} LinkQueue;

void InitQNode(LinkQueue &Q) {
  Q.front = new QNode;
  Q.rear = Q.front;
  Q.front->next = NULL;
}

bool GetHead(LinkQueue Q, ElemType &e) {
  if (Q.front == Q.rear) {
    cout << "NULL" << endl;
    return false;
  }
  e = Q.front->next->data;
  return true;
}

void EnQueue(LinkQueue &Q, ElemType e); // 无需编写，题目会提供完整代码

bool DeQueue(LinkQueue &Q, ElemType &e) {
  if (Q.front == Q.rear) {
    cout << "NULL\n";
    return false;
  }
  QNode *p = Q.front->next;
  e = p->data;
  Q.front->next = p->next;
  if (Q.rear == p)
    Q.rear = Q.front;
  delete p;
  return true;
}

int main() {
  LinkQueue Q;
  ElemType x = 0, e = 0;
  InitQNode(Q);
  cin >> x;
  while (x != -1) {
    EnQueue(Q, x);
    cin >> x;
  }
  cout << "Head:";
  if (GetHead(Q, e)) {
    cout << e << endl;
  }
  cout << "Pop:";
  while (DeQueue(Q, e)) {
    cout << e << ' ';
  }
  return 0;
}