#include <stdio.h>
int main(void)
{
	float score = 0.0;
	int a[1000] = {0};
	int max = 0,min = 100;
	int i,n;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf(" %d", &a[i]);
		score += a[i];
		if(max < a[i]) max = a[i];
		if(min > a[i]) min = a[i];
	}
	printf("%.2f", (score-max-min) / (n - 2));
	return 0;
}