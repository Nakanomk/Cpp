#include<stdio.h>
int main(void)
{
	int x, a, b;
	scanf("%d", &x);
	a = (x/2*2 == x);
	b = x > 4 && x <= 12;
	printf("%d %d %d %d", (a&&b),(a||b),(a^b),!(a||b));
	return 0;
}