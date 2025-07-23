#include<stdio.h>
int main(){
    int h1,m1,s1,h2,m2,s2,result;
     scanf("%d-%d-%d",&h1,&m1,&s1);
     scanf("%d-%d-%d",&h2,&m2,&s2);
     result=(h1-h2)*3600+(m1-m2)*60+(s1-s2);
     printf("%d",result<0?-result:result);
    return 0;
}