#include <cstdio>
#include <cstdlib>
typedef struct {
  int size, length;
  long long *element;
} LIST;
void Create(LIST *a) {
  a->element = (long long *)malloc(sizeof(long long) * 100);
  a->size = 100;
}
void Input(LIST *a) {
  scanf("%d", &a->length);
  for (int i = 0; i < a->length; i++) {
    scanf("%lld", a->element + i);
  }
}
void Output(LIST *a) {
  for (int i = 0; i < a->length; i++) {
    printf("%lld ", a->element[i]);
  }
}
void Mul(LIST *dst, const LIST *src1, const LIST *src2) {
  dst->size = src1->size < src2->size ? src1->size : src2->size;
  dst->element =
      (long long *)realloc(dst->element, sizeof(long long) * dst->size);
  dst->length = 0;
  int i1 = 0, i2 = 0;
  while (i1 < src1->length && i2 < src2->length) {
    if (src1->element[i1] < src2->element[i2]) {
      i1++;
      continue;
    }
    if (src1->element[i1] > src2->element[i2]) {
      i2++;
      continue;
    }
    dst->element[dst->length++] = src1->element[i1];
    i1++;
    i2++;
  }
}
int main() {
  LIST a, b, c;
  Create(&a);
  Create(&b);
  Create(&c);
  Input(&a);
  Input(&b);
  Mul(&c, &a, &b);
  Output(&c);
  putchar('\n');
  /*Destroy(&c);
  Destroy(&b);
  Destroy(&a);*/
  return 0;
}