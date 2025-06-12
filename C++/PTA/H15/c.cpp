#include <cstddef>
#include <stdio.h>
#include <stdlib.h>

typedef int Vertex;                /* 顶点编号类型 */
typedef char VertInfo;             /* 顶点信息类型 */
typedef struct EdgeNode *Position; /* 指针即结点位置 */
struct EdgeNode {
  Vertex dest;   /* 边的另一端点编号 */
  Position next; /* 线性表中下一个元素的位置 */
};
typedef struct HeadNode *AdjList; /* 邻接表 */
struct HeadNode {
  Position adj;  /* 邻接表头指针 */
  VertInfo data; /* 存储顶点信息 */
};
typedef struct LGraphNode *LGraph; /* 邻接表表示的图 */
struct LGraphNode {
  int n_verts;       /* 顶点数 */
  int m_edges;       /* 边数 */
  AdjList *ver_list; /* 存储顶点邻接表 */
  bool directed;     /* true为有向图，false为无向图 */
};

#define kMaxV 1000
/* 裁判实现，细节略 */
void InitGraph(LGraph graph, int kMaxVertex, bool directed);
bool ExistEdge(LGraph graph, Vertex u, Vertex v);
void InsertEdge(LGraph graph, Vertex u, Vertex v);
LGraph BuildGraph();
/* 裁判实现部分结束 */

bool IsAcyclic(LGraph graph);

int main(void) {
  LGraph graph;

  graph = BuildGraph();
  if (IsAcyclic(graph) == true) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}
/* 你的代码将被嵌在这里 */
/*
void dfs(LGraph graph, int v, int *visit, int *back, int *visited, int *time) {
  visit[v] = ++(*time);
  visited[v] = 1;
  for (Position p = graph->ver_list[v]->adj; p != NULL; p = p->next)
    if (visited[p->dest] == 0)
      dfs(graph, p->dest, visit, back, visited, time);
  back[v] = ++(*time);
}

bool IsAcyclic(LGraph graph) {
  int time = 0;
  int *visit = (int *)calloc(graph->n_verts, sizeof(int));
  int *back = (int *)calloc(graph->n_verts, sizeof(int));
  int *visited = (int *)calloc(graph->n_verts, sizeof(int));
  for (int i = 0; i < graph->n_verts; ++i)
    if (visited[i] == 0)
      dfs(graph, i, visit, back, visited, &time);
  for (int i = 0; i < graph->n_verts; ++i)
    for (Position p = graph->ver_list[i]->adj; p != NULL; p = p->next)
      if (visit[i] > visit[p->dest] && back[p->dest] > back[i])
        return false;
  return true;
}
*/
// HACK: 技巧:标记位判环
bool dfs(LGraph graph, int v, int *state) {
  state[v] = 1;
  for (Position p = graph->ver_list[v]->adj; p != NULL; p = p->next) {
    if (state[p->dest] == 1)
      return false;
    if (state[p->dest] == 0)
      dfs(graph, p->dest, state);
  }
  state[v] = 2;
  return 1;
}
bool IsAcyclic(LGraph graph) {
  int *state = (int *)calloc(graph->n_verts, sizeof(int));
  for (int i = 0; i < graph->n_verts; i++)
    if (state[i] == 0)
      if (!dfs(graph, i, state))
        return false;
  return true;
}
