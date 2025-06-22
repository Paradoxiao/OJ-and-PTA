#include <stdio.h>
#define MAX_VERTEX_NUM 14 // 最大顶点数
#define INFINITY 256      // 正无穷
#define ERROR -1
#define OK 1
#define TRUE 1
#define FALSE 0
typedef char VertexType;
typedef int Vertex;
typedef struct {
  char vexs[MAX_VERTEX_NUM];                // 存放顶点的一维数组
  int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // 邻接矩阵
  int Nv, Na;                               // 图的当前顶点数和边数
} MGraph;

int locate(MGraph G, char v) {
  int i;
  for (i = 0; i < G.Nv; i++)
    if (G.vexs[i] == v)
      return i;
  return -1;
}
void CreatMGraph(MGraph &G) {
  int i, j, k;
  char v1, v2;
  int w;
  scanf("%d%d", &G.Nv, &G.Na);
  getchar();
  for (i = 0; i < G.Nv; i++)
    scanf("%c", &G.vexs[i]);
  for (i = 0; i < G.Nv; i++)
    for (j = 0; j < G.Nv; j++)
      G.arcs[i][j] = INFINITY;
  for (k = 0; k < G.Na; k++) {
    getchar();
    scanf("%c%c %d", &v1, &v2, &w);
    i = locate(G, v1);
    j = locate(G, v2);
    G.arcs[i][j] = w;
    G.arcs[j][i] = w;
  }
}
void printGraph(MGraph G) // 打印图
{
  int i, j;
  for (i = 0; i < G.Nv; i++) {
    for (j = 0; j < G.Nv; j++)
      printf("%4d", G.arcs[i][j]);
    printf("\n");
  }
}
Vertex FindMinDist(MGraph Graph, int dist[], int collected[]);
bool Dijkstra(MGraph Graph, int dist[], Vertex S);

int main() {
  MGraph G;
  int i, j;
  int dist[MAX_VERTEX_NUM];
  CreatMGraph(G);
  i = 0;
  Dijkstra(G, dist, i);
  for (j = 0; j < G.Nv; j++)
    printf("dist[%c][%c]=%d\n", G.vexs[i], G.vexs[j], dist[j]);
  return 0;
}

/* 请在这里填写答案 */
Vertex FindMinDist(MGraph Graph, int dist[], int collected[]) {
  Vertex minIndex = -1;
  int minDist = INFINITY;
  for (int i = 0; i < Graph.Nv; i++)
    if (!collected[i] && dist[i] < minDist)
      minDist = dist[i], minIndex = i;
  return minIndex;
}
bool Dijkstra(MGraph Graph, int dist[], Vertex S) {
  int collected[MAX_VERTEX_NUM] = {0};
  for (int i = 0; i < Graph.Nv; i++)
    dist[i] = INFINITY, collected[i] = FALSE;
  dist[S] = 0;
  for (int i = 0; i < Graph.Nv - 1; i++) {
    Vertex u = FindMinDist(Graph, dist, collected);
    if (u == -1)
      break;
    collected[u] = TRUE;
    for (int v = 0; v < Graph.Nv; v++)
      if (!collected[v] && Graph.arcs[u][v] != INFINITY)
        if (dist[u] + Graph.arcs[u][v] < dist[v])
          dist[v] = dist[u] + Graph.arcs[u][v];
  }
  return TRUE;
}
