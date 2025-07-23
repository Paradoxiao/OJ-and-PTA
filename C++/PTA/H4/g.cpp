#include <cstdio>
#include <cstring>
using namespace std;
struct student {
  int p1, p2, p3;
  char num[50], name[50];
};
int main() {
  int n, i = 0, find = 0;
  scanf("%d", &n);
  student *students[n];
  for (int i = 0; i < n; i++)
    students[i] = new student;
  for (auto &i : students)
    scanf("%s %s %d %d %d", i->num, i->name, &i->p1, &i->p2, &i->p3);
  char num[50] = {0};
  scanf("%s", num);
  while (i < n)
    if (!strcmp(students[i++]->num, num)) {
      find = 1;
      for (int j = i; j < n; j++)
        students[j - 1] = students[j];
      n--;
      break;
    }
  if (find)
    for (i = 0; i < n; i++)
      printf("%s %s %d %d %d\n", students[i]->num, students[i]->name,
             students[i]->p1, students[i]->p2, students[i]->p3);
  else
    puts("error!");
  return 0;
}