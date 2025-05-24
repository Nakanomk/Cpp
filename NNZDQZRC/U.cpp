#include <bits/stdc++.h>
using namespace std;

string de(int n)
{
	string output = "";
	int sum = 0;
	bool k[16] = {0};
	bool status = 0;
	while (sum != n)
	{
		int i = 1;
		int counter = 0;
		while (i <= n - sum)
		{
			i *= 2;
			counter++;
		}
		k[counter - 1] = 1;
		sum += (i / 2);
	}
	for (int j = 15; j >= 0; j--)
	{
		if (k[j] == 1 && j != 0)
		{
			if (status)
				output += "+";
			if (j != 1)
				output += "2(" + de(j) + ")";
			else
				output += "2";
			status = 1;
		}
		else if (k[j] == 1 && j == 0)
		{
			if (status)
				output += "+";
			output += "2(0)";
		}
	}
	return output;
}

int main()
{
	int n;
	cin >> n;
	cout << de(n);
	system("pause");
	return 0;
}