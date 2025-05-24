#include <bits/stdc++.h>
using namespace std;
int tasks[5000][5000];
set<int> lists;

void check(int b)
{
	for (int i = 0; i < tasks[b - 1][0]; i++)
	{
		if (lists.find(tasks[b - 1][i + 1]) == lists.end())
		{
			lists.insert(tasks[b - 1][i + 1]);
			check(tasks[b - 1][i + 1]);
		}
	}
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> tasks[i][0];
		for (int j = 0; j < tasks[i][0]; j++)
			scanf("%d",&tasks[i][j + 1]);
	}
	check(1);
	cout << lists.size() + 1;
	system("pause");
	return 0;
}