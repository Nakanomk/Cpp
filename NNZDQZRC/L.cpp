#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct an
{
	int code;
} Ni;

typedef struct aq
{
	int length;
	int recode;
} Qi;

int main()
{
	int n, q, i;
	Ni N[1000];
	Qi Q[1000];
	scanf("%d %d", &n, &q);
	for (i = 0; i < n; i++)
	{
		scanf(" %d", &N[i].code);
	}
	for (i = 0; i < q; i++)
	{
		scanf(" %d %d", &Q[i].length, &Q[i].recode);
	}

	int c = 10;
	int cmp = 1000000000;
	for (int i = 0; i < q; i++)
	{
		c = pow(10, Q[i].length);
		cmp = 1000000000;
		for (int j = 0; j < n; j++)
		{
			if (N[j].code % c == Q[i].recode && N[j].code < cmp)
				cmp = N[j].code;
		}
		if (cmp == 1000000000)
			printf("-1\n");
		else
			printf("%d\n", cmp);
	}

	system("pause");
	return 0;
}