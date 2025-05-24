#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
int main(void)
{
	long long n;
	long long c[100000];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
	}
	long long m, p1, s1, s2;
	long long p2;
	scanf(" %lld", &m);
	scanf(" %lld", &p1);
	scanf(" %lld", &s1);
	scanf(" %lld", &s2);
	long long k1 = 0, k2 = 0, temp = 100000000000000000, tag;
	for (int i = 0; i < n; i++)
	{
		k1 += c[i] * (m - 1 - i);
	}
	k1 += (m - p1) * s1;
	for (p2 = 0; p2 < n; p2++)
	{
		k2 = abs(k1 + (m - 1 - p2) * s2);
		if (temp > k2)
		{
			temp = k2;
			tag = p2;
		}
	}

	printf("%lld", tag + 1);

	system("pause");
	return 0;
}