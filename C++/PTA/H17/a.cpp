#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 10 /* maximum number of vertices */
typedef int Vertex;     /* vertices are numbered from 0 to MaxVertexNum-1 */

typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
  Vertex AdjV;
  PtrToAdjVNode Next;
};

typedef struct Vnode {
  PtrToAdjVNode FirstEdge;
} AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode {
  int Nv;
  int Ne;
  AdjList G;
};
typedef PtrToGNode LGraph;

LGraph ReadG(); /* details omitted */

bool TopSort(LGraph Graph, Vertex TopOrder[]);

int main() {
  int i;
  Vertex TopOrder[MaxVertexNum];
  LGraph G = ReadG();

  if (TopSort(G, TopOrder) == true)
    for (i = 0; i < G->Nv; i++)
      printf("%d ", TopOrder[i]);
  else
    printf("ERROR");
  printf("\n");

  return 0;
}

/* Your function will be put here */
bool TopSort(LGraph Graph, Vertex TopOrder[]) {
  int i;
  int indegree[MaxVertexNum] = {0};
  for (i = 0; i < Graph->Nv; i++) {
    PtrToAdjVNode p = Graph->G[i].FirstEdge;
    while (p != NULL)
      indegree[p->AdjV]++, p = p->Next;
  }
  int queue[MaxVertexNum], front = 0, rear = 0;
  for (i = 0; i < Graph->Nv; i++)
    if (indegree[i] == 0)
      queue[rear++] = i;
  int count = 0;
  while (front < rear) {
    Vertex v = queue[front++];
    TopOrder[count++] = v;
    PtrToAdjVNode p = Graph->G[v].FirstEdge;
    while (p != NULL) {
      indegree[p->AdjV]--;
      if (indegree[p->AdjV] == 0)
        queue[rear++] = p->AdjV;
      p = p->Next;
    }
  }
  return count == Graph->Nv;
}
