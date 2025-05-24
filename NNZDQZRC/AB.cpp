#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> H(k,0);
	vector<int>::iterator iter1;
	vector<int>::iterator iter2;
	for(int i = 0; i < k; i++) cin >> H[i];
	sort(H.begin(), H.end());
	int counter = 0, sum = 0, room = 0;

	for(int i = 1; i <= n; i++, room += m) {
		iter1 = lower_bound(H.begin(), H.end(), i);
		iter2 = upper_bound(H.begin(), H.end(), i);
		counter = distance(iter1, iter2);
		sum += counter;
		if (counter > m && sum > room) {
			cout << "No";
			exit(0);
		}
	}
	cout << "Yes";

	system("pause");
	return 0;
}