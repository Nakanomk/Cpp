#include <bits/stdc++.h>
using namespace std;
void write(int n)
{
	if (n < 0)
	{
		n = -n;
		putchar('-');
	}
	if (n > 9)
		write(n / 10);
	putchar(n % 10 + '0');
}
void write2(int x)
{
	static int sta[35] = {0};
	int top = 0;
	if (x < 0)
	{
		x = -x;
		putchar('-');
	}
	do
	{
		sta[top++] = x % 10, x /= 10;
	} while (x);
	while (top)
		putchar(sta[--top] + '0');
}
int main()
{
	char name[30];
	printf("Please enter your name: ");
	scanf("%s", name);
	system("pause");
	return 0;
}