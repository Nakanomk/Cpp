#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	unordered_map<string, int> dict;

	for (int i = 0; i < n; ++i)
	{
		string key;
		int val;
		cin >> key >> val;
		dict[key] = val;
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int i = 0; i < m; ++i)
	{
		string m1;
		getline(cin, m1);
		string m2;
		bool status = false;
		string current_key;

		for (char c : m1)
		{
			if (c == '{')
			{
				status = true;
				current_key.clear();
			}
			else if (c == '}')
			{
				status = false;
				m2 += to_string(dict[current_key]);
			}
			else
			{
				if (status)
				{
					current_key += c;
				}
				else
				{
					m2 += c;
				}
			}
		}

		cout << m2 << endl;
	}

	system("pause");
	return 0;
}