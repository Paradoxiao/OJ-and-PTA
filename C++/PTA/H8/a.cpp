#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0
#define MAX_QSIZE 5

typedef struct {
  char name[20];
  char sex;
} QElemType;
typedef int Status;
typedef struct {
  QElemType *base;
  int front;
  int rear;
} SqQueue;

SqQueue Mdancers, Fdancers; // 分别存放男士和女士入队者队列

Status InitQueue(SqQueue &Q)

{ /* 构造一个空队列Q */
  Q.base = (QElemType *)malloc(MAX_QSIZE * sizeof(QElemType));
  if (Q.base == NULL)
    return OVERFLOW;
  Q.front = Q.rear = 0;
  return OK;
}

Status QueueEmpty(SqQueue Q) // 判断队空
{                            /* 若队列Q为空队列，则返回TRUE；否则返回FALSE */
  if (Q.front == Q.rear)     /* 队列空的标志 */
    return TRUE;
  else
    return FALSE;
}
Status EnQueue(SqQueue &Q, QElemType e) // 入队
{                                       /* 插入元素e为Q的新的队尾元素 */
  Q.base[Q.rear++] = e;
  return OK;
}

Status DeQueue(SqQueue &Q, QElemType &e) // 出队
{
  e = Q.base[Q.front++]; // 队头元素出队
  return OK;
}

void Partner(int num) { // num是志愿者总人数
  InitQueue(Mdancers);  // 男生队列初始化
  InitQueue(Fdancers);  // 女生队列初始化
  QElemType p;
  for (int i = 0; i < num; i++) // 依次将志愿者根据其性别入队
  {
    cin >> p.name >> p.sex;
    if (p.sex == 'F')
      EnQueue(Fdancers, p); // 插入女队
    else
      EnQueue(Mdancers, p); // 插入男队
  }
  if (QueueEmpty(Fdancers) || QueueEmpty(Mdancers))
    cout << "配对失败！" << endl;
  else {
    cout << "配对成功小组:" << endl;
    while (!QueueEmpty(Fdancers) &&
           !QueueEmpty(Mdancers)) { // 依次输出男女志愿者的姓名
      DeQueue(Fdancers, p);         // 女生出队
      cout << p.name << "  ";       // 输出出队女生姓名
      DeQueue(Mdancers, p);         // 男生出队
      cout << p.name << endl;       // 输出出队男生姓名
    }
  }
}

int main() {
  int num;
  cin >> num;
  Partner(num);
  return 0;
}
