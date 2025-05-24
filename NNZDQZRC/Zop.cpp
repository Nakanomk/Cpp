// 使用STL
#include <bits/stdc++.h>
using namespace std;

int read(void)
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

int main(void)
{
	int n, Q;
	cin >> n >> Q;
	vector<int> Memory(n, -1);
	set<int> solutions;
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		a = read(), b = read(), c = read();
		int solution = (c - b) / a;
		solutions.insert(solution);
	}
	int j = solutions.size() - 1;
	int index = 0;
	for (int a : solutions)
	{
		Memory[index] = a;
		index++;
	}
	vector<int>::iterator iter1;
	vector<int>::iterator iter2;
	for (int i = 0; i < Q; i++)
	{
		int L, R;
		L = read(), R = read();
		iter1 = lower_bound(Memory.begin(), Memory.begin() + index, L);
		iter2 = upper_bound(Memory.begin(), Memory.begin() + index, R);
		cout << distance(iter1, iter2) << endl;
	}
	system("pause");
	return 0;
}