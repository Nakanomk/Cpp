#include <bits/stdc++.h>
using namespace std;

int s1, s2, s3, s4;
set<int> total;
vector<int> man(2, 0);

void dfs(vector<int> &man, int er, int layer, vector<int> &sub)
{
	int top = sub.size();
	if (layer == top)
	{
		int a = max(man[0], man[1]);
		total.insert(a);
		return;
	}
	if (layer != -1)
		man[er] += sub[layer];
	dfs(man, 0, layer + 1, sub);
	dfs(man, 1, layer + 1, sub);
}
int main(void)
{
	cin >> s1 >> s2 >> s3 >> s4;
	vector<int> A(s1), B(s2), C(s3), D(s4);
	for (int i = 0; i < s1; i++)
	{
		scanf(" %d", &A[i]);
	}
	for (int i = 0; i < s2; i++)
	{
		scanf(" %d", &B[i]);
	}
	for (int i = 0; i < s3; i++)
	{
		scanf(" %d", &C[i]);
	}
	for (int i = 0; i < s4; i++)
	{
		scanf(" %d", &D[i]);
	}
	dfs(man, 0, -1, A);
	int result = *total.begin();
	total.clear();
	dfs(man, 0, -1, B);
	result += *total.begin();
	total.clear();
	dfs(man, 0, -1, C);
	result += *total.begin();
	total.clear();
	dfs(man, 0, -1, D);
	result += *total.begin();

	cout << result;
	system("pause");
	return 0;
}