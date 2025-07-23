#include<stdio.h>

int main ()
{
	char a[3];
	gets(a);
	printf("%.3d %.3o %.3x\n%.3d %.3o %.3x\n%.3d %.3o %.3x\n",a[0],a[0],a[0],a[1],a[1],a[1],a[2],a[2],a[2]);
	return 0;
}


