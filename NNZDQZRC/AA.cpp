#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int N, B, i;
	cin >> N >> B;
	vector<int> H(N, 0);
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		scanf(" %d", &H[i]);
	}
	sort(H.begin(), H.end(), greater<int>());

	for (i = 0; sum < B; i++)
		sum += H[i];
	cout << i << endl;

	system("pause");
	return 0;
}