#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll QuickPower(ll base, ll power)
{
	ll result = 1;
	while (power)
	{
		if (power & 1)
		{
			result *= base;
		}
		base *= base;
		power >>= 1;
	}
	return result;
}

void request(ll a, ll k)
{
	ll temp = 1, count = 0;
	for (ll i = 2; i <= sqrt(a); i++)
	{
		count = 0;
		while (!(a % i))
		{
			count++;
			a /= i;
		}
		if (count >= k)
			temp *= QuickPower(i, count);
	}
	cout << temp << endl;
}

int main(void)
{
	ll q;
	cin >> q;
	for (ll i = 0; i < q; i++)
	{
		ll a, k;
		cin >> a >> k;
		request(a, k);
	}
	system("pause");
	return 0;
}