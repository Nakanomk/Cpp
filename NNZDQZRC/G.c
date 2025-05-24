#include<stdio.h>
int main(void)
{
	int x,i = 0;
	scanf("%d", &x);
	while(x != 1) {
		i++;
		x /= 2;
	}
	printf("%d", i+1);
	return 0;
}