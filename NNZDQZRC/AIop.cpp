#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, d;
int main()
{
	cin >> n >> d;
	vector<vector<ll>> Q(n, vector<ll>(d, 0)), K(d, vector<ll>(n, 0)), V(n, vector<ll>(d, 0));
	vector<ll> W(n, 0);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < d; ++j)
			cin >> Q[i][j];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < d; ++j)
			cin >> K[j][i];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < d; ++j)
			cin >> V[i][j];
	for (int i = 0; i < n; ++i)
		cin >> W[i];
	vector<vector<ll>> ans(n, vector<ll>(d, 0));
	for (int i = 0; i < d; ++i)
		for (int j = 0; j < d; ++j)
			for (int k = 0; k < n; ++k)
				ans[i][j] += K[i][k] * V[k][j];
	vector<vector<ll>> ans2(n, vector<ll>(d, 0));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < d; ++j)
			Q[i][j] *= W[i];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < d; ++j)
			for (int k = 0; k < d; ++k)
				ans2[i][j] += (Q[i][k] * ans[k][j]);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < d; ++j)
			cout << ans2[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}