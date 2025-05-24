#include <bits/stdc++.h>
using namespace std;

int read(void)
{
	int x = 0, w = 1;
	char ch = 0;
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			w = -1;
		ch = getchar(); 
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + (ch - '0'); 
		ch = getchar();
	}
	return x * w;
}

int main(void)
{
	int n = read(), m = read();
	int dx = 0,dy = 0;
	for(int i = 0; i < n; i++)
		dx += read(), dy += read();
	for(int i = 0; i < m; i++) {
		int x = read(), y = read();
		x += dx, y+= dy;
		printf("%d %d\n",x, y);
	}
	system("pause");
	return 0;
}