#include <cstddef>
#include <cstdlib>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int dataType;

typedef struct _node {
  dataType data;
  struct _node *prev; // 指向前驱的指针
  struct _node *next; // 指向后继的指针
} node;

typedef node *List;

// 创建一个空的循环链表，返回指向头节点的指针。
List create_list() {
  node *head = (node *)malloc(sizeof(node));
  head->next = head->prev = head;
  return head;
}
// 用尾插法向链表L中插入数据域等于x的结点
void insert(List L, dataType x) {
  node *temp = L->prev;
  temp->next = (node *)malloc(sizeof(node));
  temp->next->prev = temp;
  temp->next->data = x;
  temp->next->next = L;
  L->prev = temp->next;
}
// 如果链表为空，则返回true,否则返回false。
bool is_empty(List L) {
  return L->next == L;
}
// 顺序遍历链表L。输出所有结点的数据域。如果链表为空则输出NULL
void traverse(List L) {
  if (is_empty(L)) {
    puts("NULL");
    return;
  }
  node *p = L->next;
  while (p != L) {
    printf("%d ", p->data);
    p = p->next;
  }
  putchar('\n');
}
// 逆序遍历链表L。输出所有结点的数据域。如果链表为空则输出NULL
void traverse_back(List L) {
  if (is_empty(L)) {
    puts("NULL");
    return;
  }
  node *p = L->prev;
  while (p != L) {
    printf("%d ", p->data);
    p = p->prev;
  }
  putchar('\n');
}
// 返回第1个指向数据域等于x的结点的指针。如果没有则返回NULL。
node *search(List L, dataType x) {
  node *p = L->next;
  while (p != L) {
    if (p->data == x)
      return p;
    p = p->next;
  }
  return NULL;
}
// 删除指针p指向的结点。调用者保证p是合法的。
// 返回p指向结点后继结点的指针。
// 若p指向链表最后一个结点，返回指向头结点的指针。
node *delete_node(List L, node *p) {
  p->prev->next = p->next;
  p->next->prev = p->prev;
  return p->next;
}
// 删除链表L中所有数据域等于x的结点
void remove_node(List L, dataType x) {
  if (is_empty(L))
    return;
  node *p = L->next;
  while (p != L)
    if (p->data == x)
      p = delete_node(L, p);
    else
      p = p->next;
}
// 使链表L成为一个空链表
void make_empty(List L) {
  L->next = L->prev = L;
}
// 销毁链表L
void destroy_list(List L) {
  L = NULL;
}

int main() {
  int x;
  List mylist = create_list();
  // 输入一系列正整数，输入0表示输入结束
  // 用尾插法插入链表
  scanf("%d", &x);
  while (x != 0) {
    insert(mylist, x);
    scanf("%d", &x);
  }
  // 顺序遍历链表
  traverse(mylist);
  // 逆序遍历链表
  traverse_back(mylist);
  // 输入要删除的结点数据域
  scanf("%d", &x);
  node *p = search(mylist, x);
  if (p != NULL) {
    delete_node(mylist, p);
  }
  // 顺序遍历链表
  traverse(mylist);
  // 逆序遍历链表
  traverse_back(mylist);
  // 输入要删除的结点数据域
  scanf("%d", &x);
  remove_node(mylist, x);
  // 顺序遍历链表
  traverse(mylist);
  // 逆序遍历链表
  traverse_back(mylist);
  // 销毁链表
  destroy_list(mylist);
  return 0;
}

/* 请在这里填写答案 */
