#include <bits/stdc++.h>
using namespace std;

typedef struct skill
{
	int t;
	int c;
} S;

void quickSort(vector<S> &Skills, int start, int end)
{
	if (start < end)
	{
		S base_element = Skills[start];
		int base = Skills[start].t;
		int left = start;
		int right = end;
		while (left < right)
		{
			while (left < right && Skills[right].t >= base)
			{
				right--;
			}
			Skills[left] = Skills[right];
			while (left < right && Skills[left].t <= base)
			{
				left++;
			}
			Skills[right] = Skills[left];
		}
		Skills[left] = base_element;
		quickSort(Skills, start, left - 1);
		quickSort(Skills, left + 1, end);
	}
}

int main(void)
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<S> Skills(n);
	for (int i = 0; i < n; i++)
	{
		cin >> Skills[i].t >> Skills[i].c;
	}
	quickSort(Skills, 0, Skills.size() - 1);

	int consumption = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		consumption += Skills[i].c;
		int limit = k;
		if (i > 0)
			limit = Skills[i - 1].t;
		while (Skills[i].t > limit)
		{
			if (m >= consumption)
			{
				m -= consumption;
				Skills[i].t--;
			}
			else
			{
				cout << Skills[i].t;
				system("pause");
				return 0;
			}
		}
	}
	cout << k;
	system("pause");
	return 0;
}