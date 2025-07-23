#include<stdio.h>

int main ()
{
	int a,b;
	scanf("%d %d",&a,&b);
	printf("Octal Decimal Hexadecimal\n%-6o%-8d%x\n%-6o%-8d%x",a,a,a,b,b,b);
	return 0;
}


