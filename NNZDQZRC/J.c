#include <stdio.h>
int main(void)
{
	int i, n, x, t = 0;
	scanf("%d %d", &n, &x);
	for (i = 1; i <= n; i++)
	{
		if (i / 1000000 == x && i > 999999)
			t++;
		if (i / 100000 % 10 == x && i > 99999)
			t++;
		if (i / 10000 % 10 == x && i > 9999)
			t++;
		if (i / 1000 % 10 == x && i > 999)
			t++;
		if (i / 100 % 10 == x && i > 99)
			t++;
		if (i / 10 % 10 == x && i > 9)
			t++;
		if (i % 10 == x)
			t++;
	}
	printf("%d", t);
	return 0;
}