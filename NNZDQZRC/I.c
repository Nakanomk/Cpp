#include <stdio.h>
int main(void)
{
	int i, j, S, sum = 2, n = 0, status;
	scanf("%d", &S);
	if(S >= 2) {
		printf("2\n");
		n++;
	}
	for (i = 3; i < 5000  && (sum + i) <= S; i++)
	{
		status = 1;
		for (j = 2; j < i; j++)
		{
			if (i == i / j * j)
			{
				status = 0;
				break;
			}
		}
		if (status == 1)
		{
			sum += i;
			printf("%d\n", i);
			n++;
		}
	}
	printf("%d", n);
	return 0;
}