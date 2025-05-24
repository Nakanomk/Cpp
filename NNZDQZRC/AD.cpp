#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> V(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &V[i][j]);
		}
	}
	vector<int> target(n, 0);
	for (int i = 0; i < n; i++)
	{
		int status = 1;
		fill(target.begin(), target.end(), 0);
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (V[i][j] < V[k][j])
					target[k]++;
				if (target[k] == m)
				{
					cout << k + 1 << endl;
					status = 0;
					break;
				}
			}
		}
		if (status)
			cout << "0" << endl;
	}

	system("pause");
	return 0;
}