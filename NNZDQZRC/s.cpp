#include <bits/stdc++.h>
using namespace std;

int main()
{
	string S, S1, T, T1;
	cin >> S >> T;
	int Q;
	cin >> Q;
	int ls, rs, lt, rt;
	for (int i = 0; i < Q; i++)
	{
		cin >> ls >> rs >> lt >> rt;
		string S1(S, ls - 1, rs - ls + 1);
		string T1(T, lt - 1, rt - lt + 1);
		if (S1 < T1)
			cout << "yifusuyi" << endl;
		else if (S1 > T1)
			cout << "erfusuer" << endl;
		else
			cout << "ovo" << endl;
	}
	system("pause");
	return 0;
}