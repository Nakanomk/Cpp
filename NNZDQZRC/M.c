#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j, a, b = 0, index = 0;
	int sum = 0;
	scanf(" %d", &j);
	while (sum < j * j)
	{
		scanf(" %d", &i);
		sum += i;
		for (a = 0; a < i; a++)
		{
			if (b == 0)
				printf("0");
			else
				printf("1");
			index++;
			if (index % j == 0 && index != 0 && index != j * j)
				printf("\n");
		}
		b = 1 - b;
	}

	system("pause");
	return 0;
}