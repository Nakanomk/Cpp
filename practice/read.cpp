#include <bits/stdc++.h>
using namespace std;
int main()
{
	char ch = 0;
	int x = 1, f = 0;
	while (!(isdigit(ch)))
	{
		if (ch == '-')
			x = -x;
		ch = getchar();
	}
	while (isdigit(ch))
	{
		f = 10 * f + ch - '0';
		ch = getchar();
	}
	cout << x * f;
	system("pause");
	return 0;
}