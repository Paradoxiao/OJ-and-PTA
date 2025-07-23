#include<stdio.h>
int main(){
     int a,a1,a2,a3,a4;
     scanf("%d",&a);
     a1=a2=a3=a4=a;
     printf("  a   : %d\n--a   : %d\n  a-- : %d\n  a++ : %d\n++a   : %d",a,--a1,a2--,a3++,++a4);
    return 0;
}