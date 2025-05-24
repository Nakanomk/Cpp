// 不使用STL
#include <bits/stdc++.h>
using namespace std;

int upperbound(int R, int *a, int EC)
{
	int L = 0;
	while (L < R)
	{
		int mid = (L + R) / 2;
		if (a[mid] <= EC)
			L = mid + 1;
		else
			R = mid;
	}
	return L;
}

int lowerbound(int R, int *a, int EC)
{
	int L = 0;
	while (L < R)
	{
		int mid = (L + R) / 2;
		if (a[mid] < EC)
			L = mid + 1;
		else
			R = mid;
	}
	return L;
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void quicksort(int *a, int l, int r)
{
	if (l >= r)
		return;
	int i = l, j = r, x = a[(l + r) / 2];
	do
	{
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i <= j);
	quicksort(a, l, j);
	quicksort(a, i, r);
}

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

int noother(int a[], int b, int n)
{
	for(int i = 0; i < n; i++)
		if(a[i] == b)
			return 0;
	return 1;
}

int main(void)
{
	int n, Q, j = 0;
	cin >> n >> Q;
	int Memory[10000] = {0};
	int solutions[90000] = {0};
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		a = read(), b = read(), c = read();
		int solution = (c - b) / a ;
		solutions[solution] = 1;
	}
	for(int i = 0; i < 90000; i++) {
		if(solutions[i] == 1) {
			Memory[j] = i;
			j++;
		}
	}
	for (int i = 0; i < Q; i++)
	{
		int L, R;
		L = read(), R = read();
		int Lbound = lowerbound(j, Memory, L);
		int Ubound = upperbound(j, Memory, R);
		printf("%d\n", Ubound - Lbound);
	}
	system("pause");
	return 0;
}