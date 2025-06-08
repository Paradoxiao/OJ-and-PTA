// 在这里给出函数被调用进行测试的例子。例如：
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#define MVNum 100          // 最大顶点数
typedef struct ArcNode {   // 表结点
  int adjvex;              // 邻接点的位置
  struct ArcNode *nextarc; // 指向下一个表结点的指针
} ArcNode;
typedef struct VNode {
  char data;             // 顶点信息
  ArcNode *firstarc;     // 指向第一个表结点的指针
} VNode, AdjList[MVNum]; // AdjList表示邻接表类型
typedef struct {
  AdjList vertices;   // 头结点数组
  int vexnum, arcnum; // 图的当前顶点数和边数
} ALGraph;
void CreatMGraph(ALGraph &G); /* 创建图 */
void printGraph(ALGraph G);   /*输出图 */
int main() {
  ALGraph G;
  CreatMGraph(G);
  printGraph(G);
  return 0;
}

void printGraph(ALGraph G) {
  int i;
  ArcNode *p;
  for (i = 0; i < G.vexnum; i++) {
    printf("%c:", G.vertices[i].data);
    for (p = G.vertices[i].firstarc; p; p = p->nextarc)
      printf(" %c", G.vertices[p->adjvex].data);
    printf("\n");
  }
}

/* 请在这里填写答案 */
void CreatMGraph(ALGraph &G) {
  int n, m;
  scanf("%d %d", &n, &m);
  G.vexnum = n, G.arcnum = m;
  for (int i = 0; i < n; i++) {
    scanf(" %c", &G.vertices[i].data);
    G.vertices[i].firstarc = nullptr;
  }
  char a, b;
  int j, k;
  for (int i = 0; i < m; i++) {
    scanf(" %c %c", &a, &b);
    for (j = 0; j < n && G.vertices[j].data != a; j++)
      ;
    for (k = 0; k < n && G.vertices[k].data != b; k++)
      ;
    ArcNode *new_node_l = (ArcNode *)malloc(sizeof(ArcNode));
    ArcNode *new_node_r = (ArcNode *)malloc(sizeof(ArcNode));
    new_node_l->adjvex = j, new_node_r->adjvex = k;
    new_node_l->nextarc = nullptr, new_node_r->nextarc = nullptr;
    if (!G.vertices[j].firstarc)
      G.vertices[j].firstarc = new_node_r;
    else {
      new_node_r->nextarc = G.vertices[j].firstarc;
      G.vertices[j].firstarc = new_node_r;
    }
    if (!G.vertices[k].firstarc)
      G.vertices[k].firstarc = new_node_l;
    else {
      new_node_l->nextarc = G.vertices[k].firstarc;
      G.vertices[k].firstarc = new_node_l;
    }
  }
}