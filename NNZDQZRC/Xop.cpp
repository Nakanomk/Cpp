#include <bits/stdc++.h>
using namespace std;

int calTime(vector<int> &sub, int num)
{
	if (num == 1)
		return sub[0];
	if (num == 2)
		return max(sub[0], sub[1]);

	int time = 0;
	int left = 0, right = num - 1;

	while (left <= right)
	{
		if (left == right)
		{
			time += sub[left];
			break;
		}
		sub[right]--;
		sub[right - 1]--;
		if (sub[right] == 0)
			right--;
		if (sub[right - 1] == 0)
			right--;
		time++;
	}
	return time;
}

int main(void)
{
	int s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	vector<int> A(s1), B(s2), C(s3), D(s4);

	for (int i = 0; i < s1; i++)
		cin >> A[i];
	for (int i = 0; i < s2; i++)
		cin >> B[i];
	for (int i = 0; i < s3; i++)
		cin >> C[i];
	for (int i = 0; i < s4; i++)
		cin >> D[i];

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	sort(C.begin(), C.end());
	sort(D.begin(), D.end());

	int total = 0;
	total += calTime(A, s1);
	total += calTime(B, s2);
	total += calTime(C, s3);
	total += calTime(D, s4);

	cout << total << endl;
	return 0;
}