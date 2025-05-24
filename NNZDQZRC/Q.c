#include <bits/stdc++.h>
using namespace std;

int main()
{
	set<string> s;
	int n, m, k;
	string w;

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> w;
		s.insert(w);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> w;
		s.erase(w);
	}
	for (int i = 0; i < k; i++)
	{
		cin >> w;
		s.insert(w);
	}
	for (string c : s)
	{
		cout << c << endl;
	}
	system("pause");
	return 0;
}