#include<stdio.h>
#define  M_PI 3.14159265358979323846
int main(){
     double d,r;
    scanf("%lf",&d);
    r=d/2;
    printf("area = %.6lf\nvolume = %.6lf",4*M_PI*r*r,4*M_PI*r*r*r/3);
    return 0;
}