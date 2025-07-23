#include <stdio.h>
struct vec {
  int x, y;
};
void get_vec(struct vec *a, struct vec *b) {
  scanf("%d %d", &a->x, &a->y);
  scanf("%d %d", &b->x, &b->y);
}
void put_vec_sum(struct vec a, struct vec b) {
  printf("%d %d", a.x + b.x, a.y + b.y);
}
int main() {
  struct vec a, b;
  get_vec(&a, &b);
  put_vec_sum(a, b);
}
