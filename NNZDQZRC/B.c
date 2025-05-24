#include <stdio.h>
int main(void)
{
	float s, x = 2.0, sum = 0.0;
	int i = 0;
	scanf("%f", &s);
	while (sum < s)
	{
		i++;
		sum += x;
		x *= 0.98;
	}
	printf("%d", i);
	return 0;
}