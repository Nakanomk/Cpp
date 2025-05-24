#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	cin.ignore();
	int counter = 1;
	vector<vector<string>> M(n, vector<string>(8));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			getline(cin, M[i][j]);
		}
		counter = 1;
		for (int k = 0; k < i; k++)
		{
			int linecounter = 0;
			for (int t = 0; t < 8; t++)
			{
				if (M[i][t] == M[k][t])
					linecounter++;
			}
			if(linecounter == 8)
				counter++;
		}
		cout << counter << endl;
	}
	system("pause");
	return 0;
}