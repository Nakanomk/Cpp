#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	int i, j;
	double x, y;
	vector<int> TransType(n+1);
	vector<double> TransVal(n+1);
	vector<vector<double>> TransEffect(n + 1, vector<double>{1.0, 0.0});
	vector<double> temp = TransEffect[0];
	for (int p = 1; p <= n; p++)
	{
		scanf(" %d %lf", &TransType[p], &TransVal[p]);
		int Type = TransType[p] - 1;
		if (Type)
		{
			TransEffect[p][Type] = temp[Type] + TransVal[p];
			TransEffect[p][!Type] = temp[!Type];
		}
		else
		{
			TransEffect[p][Type] = temp[Type] * TransVal[p];
			TransEffect[p][!Type] = temp[!Type];
		}
		temp[Type] = TransEffect[p][Type];
		temp[!Type] = TransEffect[p][!Type];
	}
	for (int k = 0; k < m; k++)
	{
		scanf(" %d %d %lf %lf", &i, &j, &x, &y);
		x *= TransEffect[j][0] / TransEffect[i - 1][0], y *= TransEffect[j][0] / TransEffect[i - 1][0];
		double dx = x * cos(TransEffect[j][1] - TransEffect[i - 1][1]) - y * sin(TransEffect[j][1] - TransEffect[i - 1][1]);
		double dy = x * sin(TransEffect[j][1] - TransEffect[i - 1][1]) + y * cos(TransEffect[j][1] - TransEffect[i - 1][1]);
		printf("%.2lf %.2lf\n", dx, dy);
	}
	system("pause");
	return 0;
}