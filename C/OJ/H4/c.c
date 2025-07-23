#include<stdio.h>
int main(){
     int money,a,b,c,d,temp;
     scanf("%d",&money);
    temp=100-money;
    a=temp/20;
    temp=temp%20;
    b=temp/10;
    temp=temp%10;
    c=temp/5;
    temp=temp%5;
    d=temp;
    printf("$20 bills: %d\n$10 bills: %d\n $5 bills: %d\n $1 bills: %d\n",a,b,c,d);
    return 0;
}