#include <stdio.h>
#define MVNum 100 // 最大顶点数
typedef struct {
  char vexs[MVNum];       // 存放顶点的一维数组
  int arcs[MVNum][MVNum]; // 邻接矩阵
  int vexnum, arcnum;     // 图的当前顶点数和边数
} MGraph;
void CreatMGraph(MGraph &G); /* 创建图 */
void printGraph(MGraph G);   /*输出图 */

int main() {
  MGraph G;
  CreatMGraph(G); // 创建图G
  printGraph(G);  // 打印该图
  return 0;
}

void printGraph(MGraph G) // 打印图
{
  int i, j;
  for (i = 0; i < G.vexnum; i++) {
    printf("%c:", G.vexs[i]);
    for (j = 0; j < G.vexnum; j++)
      if (G.arcs[i][j])
        printf(" %c", G.vexs[j]);
    printf("\n");
  }
}

/* 请在这里填写答案 */
void CreatMGraph(MGraph &G) {
  int n, m;
  scanf("%d %d", &n, &m);
  G.vexnum = n, G.arcnum = m;
  for (int i = 0; i < n; i++)
    scanf(" %c", G.vexs + i);
  char a, b;
  int i, j;
  for (int k = 0; k < m; k++) {
    scanf(" %c %c", &a, &b);
    for (i = 0; i < n && G.vexs[i] != a; i++)
      ;
    for (j = 0; j < n && G.vexs[j] != b; j++)
      ;
    G.arcs[i][j] = 1, G.arcs[j][i] = 1;
  }
}