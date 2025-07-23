#include <cstdio>
using namespace std;
struct LNode {
  int data;
  LNode *next;
  LNode(int data) : data(data), next(nullptr) {}
};
class L {
public:
  LNode *head, *cur;
  L() {
    head = cur = new LNode(0);
  }
  void add(int data) {
    cur->next = new LNode(data);
    cur = cur->next;
  }
  void input() {
    int n;
    scanf("%d", &n);
    while (n != -1) {
      add(n);
      scanf("%d", &n);
    }
    cur = head;
  }
};
int main() {
  L a, b, c;
  a.input();
  b.input();
  while (a.cur->next && b.cur->next) {
    if (a.cur->next->data <= b.cur->next->data) {
      c.add(a.cur->next->data);
      a.cur = a.cur->next;
    } else {
      c.add(b.cur->next->data);
      b.cur = b.cur->next;
    }
  }
  if (!a.cur->next) {
    while (b.cur->next) {
      c.add(b.cur->next->data);
      b.cur = b.cur->next;
    }
  } else {
    c.add(a.cur->next->data);
    a.cur = a.cur->next;
  }
  c.cur = c.head;
  if (!c.cur->next) {
    puts("NULL");
    return 0;
  }
  for (int i = 0; c.cur->next; c.cur = c.cur->next, i = 1)
    printf(i ? " %d" : "%d", c.cur->next->data);
  return 0;
}