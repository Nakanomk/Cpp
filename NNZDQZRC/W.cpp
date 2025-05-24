#include <bits/stdc++.h>
using namespace std;

bool used[20] = {0};
int com[20] = {0};
int n, k;
int ans = 0;
int x[20] = {0};

int sum(void)
{
	int sum = 0;
	for (int i = 0; i < k; i++)
	{
		sum += com[i];
	}
	return sum;
}

bool check_prime(int num)
{
	if (num == 1)
		return false;
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

void comGet(int start, int layer)
{
	if (layer == k)
	{
		if (check_prime(sum()))
			ans++;
		else
			return;
	}
	for (int i = start; i < n; i++)
	{
		if (!used[i])
		{
			used[i] = true;
			com[layer] = x[i];
			comGet(i + 1, layer + 1);
			used[i] = 0;
		}
	}
}

int main(void)
{

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	comGet(0, 0);
	cout << ans;

	system("pause");
	return 0;
}