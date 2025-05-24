#include <stdio.h>
int main(void)
{
	int a[3];
	scanf("%d %d %d", &a[0], &a[1], &a[2]);
	int i, j, temp;
	for (i = 0; i < 2; i++)
	{
		for (j = 1; j < 3 - i + 1; j++)
		{
			if (a[j] < a[j - 1])
			{
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
		}
	}
	printf("%d %d %d", a[0], a[1], a[2]);
	return 0;
}