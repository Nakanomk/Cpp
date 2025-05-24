#include <iostream>
#include <cstdlib>

using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Bs(int c[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n - i; j++)
		{
			if (c[j] < c[j - 1])
				swap(&c[j], &c[j - 1]);
		}
	}
}

int main(void)
{
	int n, k;
	cin >> n >> k;
	int c[10000];
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
	}
	Bs(c, n);

	int tag = 1;
	for (int i = 1; i < n; i++)
	{
		if (c[i] != c[i - 1])
			tag++;
		if (tag == k) {
			cout << c[i];
			break;
		}
	}
	if (tag < k)
		cout << "NO RESULT";

	system("pause");
	return 0;
}