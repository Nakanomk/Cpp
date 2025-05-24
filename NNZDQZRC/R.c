#include <bits/stdc++.h>
using namespace std;

int getlength(char *c)
{
	int p = 0;
	while (c[p] != 0)
	{
		p++;
	}
	return p;
}

int main()
{
	char w[100];
	memset(w, 0, 100);
	cin >> w;
	multiset<string> ms;
	int i, j, a, b;
	char w2[100];
	int wlength;
	wlength = getlength(w);
	for (i = 0; i < wlength; i++)
	{
		for (j = wlength - 1; j > i; j--)
		{
			for (int k = 0; k < 100; k++)
				w2[k] = w[k];
			a = i;
			b = j;
			while (a < b)
			{
				w2[a] = w[b];
				w2[b] = w[a];
				a++;
				b--;
			}
			string str(w2, wlength);
			ms.insert(str);
		}
	}
	string str(w,wlength);
	ms.insert(str);
	cout << *(ms.begin());
	system("pause");
	return 0;
}