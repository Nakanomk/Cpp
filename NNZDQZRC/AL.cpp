#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1, 1), b(n, 0), c(n + 1, 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		c[i] = a[i] * c[i - 1];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		b[i] = m / c[i];
		m %= c[i];
	}
	for (int i = 0; i < n; i++)
		cout << b[i] << " ";

	system("pause");
	return 0;
}