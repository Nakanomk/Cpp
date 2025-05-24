#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	ll N, a, b;
	cin >> N >> a >> b;
	ll count = 0;
	ll s[4];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> s[j];
			if (s[j] < 0)
				s[j] = 0;
			if ((j % 2) && s[j] > a)
				s[j] = a;
			if ((!(j % 2)) && s[j] > b)
				s[j] = b;
		}
		count += ((s[2] - s[0]) * (s[3] - s[1]));
	}
	cout << count;

	system("pause");
	return 0;
}