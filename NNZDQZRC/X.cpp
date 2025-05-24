#include <bits/stdc++.h>
using namespace std;

int Getpri(vector<int>& sub, int num, int t1, int t2)
{
	int temp = 0, p = 0;
	for (int i = 0; i < num; i++) {
		if(sub[i] > temp && i != t1 && i != t2) {
			temp = sub[i];
			p = i;
		}
	}
	if(temp != 0) return p;
	else return -1;
}

int calTime(vector<int> &sub, int num)
{
	bool status[2] = {1, 1};
	int count = 0;
	int thread_1 = num - 1;
	int thread_2 = num - 2;
	if (num == 1)
		return sub[0];
	if (num == 2)
		return max(sub[0], sub[1]);
	while (thread_1 >= 0 || thread_2 >= 0)
	{
		if (status[0] == true)
			sub[thread_1]--;
		if (status[1] == true)
			sub[thread_2]--;
		count++;
		if (sub[thread_1] == 0)
		{
			thread_1 = Getpri(sub, num, thread_1, thread_2);
			if (thread_1 < 0)
				status[0] = false;
		}
		if (sub[thread_2] == 0)
		{
			thread_2 = Getpri(sub, num, thread_1, thread_2);
			if (thread_2 < 0)
				status[1] = false;
		}
	}
	return count;
}

int main(void)
{
	int s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	vector<int> A(s1), B(s2), C(s3), D(s4);
	int num;
	for (int i = 0; i < s1; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < s2; i++)
	{
		cin >> B[i];
	}
	for (int i = 0; i < s3; i++)
	{
		cin >> C[i];
	}
	for (int i = 0; i < s4; i++)
	{
		cin >> D[i];
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	sort(C.begin(), C.end());
	sort(D.begin(), D.end());

	int total = 0;
	total += calTime(A, s1);
	total += calTime(B, s2);
	total += calTime(C, s3);
	total += calTime(D, s4);

	cout << total;
	system("pause");
	return 0;
}