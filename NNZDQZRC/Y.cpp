#include <bits/stdc++.h>
using namespace std;

void SuperFunc(int option, vector<int> &a)
{
	vector<int>::iterator iter1;
	vector<int>::iterator iter2;
	
	int x, y, counter = 0;
	int length = a.size();
	if (option == 1)
		cin >> x;
	else
		cin >> x >> y;
	switch (option)
	{
	case 1:
		iter1 = lower_bound(a.begin(), a.end(), x);
		iter2 = upper_bound(a.begin(), a.end(), x);
		counter = distance(iter1, iter2);
		break;
	case 2:
		iter1 = lower_bound(a.begin(), a.end(), x);
		iter2 = upper_bound(a.begin(), a.end(), y);
		counter = distance(iter1, iter2);
		break;
	case 3:
		iter1 = lower_bound(a.begin(), a.end(), x);
		iter2 = lower_bound(a.begin(), a.end(), y);
		counter = distance(iter1, iter2);
		break;
	case 4:
		iter1 = upper_bound(a.begin(), a.end(), x);
		iter2 = upper_bound(a.begin(), a.end(), y);
		counter = distance(iter1, iter2);
		break;
	case 5:
		iter1 = upper_bound(a.begin(), a.end(), x);
		iter2 = lower_bound(a.begin(), a.end(), y);
		counter = distance(iter1, iter2);
		break;
	}
	if (counter < 0)
		counter = 0;
	cout << counter << endl;
}
int main(void)
{
	int n, m, p;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		scanf(" %d", &a[i]);
	sort(a.begin(), a.end());
	for (int i = 0; i < m; i++)
	{
		scanf(" %d", &p);
		SuperFunc(p, a);
	}

	system("pause");
	return 0;
}