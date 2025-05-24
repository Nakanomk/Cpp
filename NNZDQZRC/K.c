#include <stdio.h>
int main(void)
{
	int Mi, Ni, M[1001], N[1001], i, j, check_time = 0;
	for (i = 0; i < 1001; i++)
	{
		M[i] = -1;
		N[i] = -1;
	} // MNP置-1
	scanf("%d %d", &Mi, &Ni);
	for (i = 0; i < Ni; i++)
		scanf(" %d", &N[i]);
	int index = 0, status = 0;
	for (i = 0; i < Ni; i++)
	{
		status = 0;
		for (j = 0; j < Mi; j++)
		{
			if (N[i] == M[j])
			{
				status = 1;
				break;
			}
		}
		if (status == 0)
		{
			if (index == Mi)
				index = 0;
			M[index] = N[i];
			index++;
			check_time++;
		}
	}
	printf("%d", check_time);
	return 0;
}