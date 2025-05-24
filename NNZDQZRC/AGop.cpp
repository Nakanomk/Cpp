#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	double qzj[100000], qzh[100000];
	cin >> n >> m;
	int type;
	double x;
	cin >> type >> x;
	if (type == 1) // 初始化，单独处理，合到for循环里面写也行，复制粘贴的事
	{
		qzj[0] = x;
		qzh[0] = 0.0;
	}
	else
	{
		qzj[0] = 1.0;
		qzh[0] = x;
	}
	for (int i = 1; i < n; ++i)
	{
		cin >> type >> x;
		if (type == 1)
		{
			qzj[i] = qzj[i - 1] * x;
			qzh[i] = qzh[i - 1];
		}
		else
		{
			qzj[i] = qzj[i - 1];
			qzh[i] = qzh[i - 1] + x;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int j, k;
		double x, y;
		cin >> j >> k >> x >> y;
		cout.setf(ios::fixed);
		if (j != 1)
		{
			cout << setprecision(3) << (x * cos(qzh[k - 1] - qzh[j - 2]) - y * sin(qzh[k - 1] - qzh[j - 2])) * qzj[k - 1] / qzj[j - 2] << " ";
			cout << setprecision(3) << (x * sin(qzh[k - 1] - qzh[j - 2]) + y * cos(qzh[k - 1] - qzh[j - 2])) * qzj[k - 1] / qzj[j - 2] << endl;
		}
		else
		{
			cout << setprecision(3) << (x * cos(qzh[k - 1]) - y * sin(qzh[k - 1])) * qzj[k - 1] << " ";
			cout << setprecision(3) << (x * sin(qzh[k - 1]) + y * cos(qzh[k - 1])) * qzj[k - 1] << endl;
		}
	}
	return 0;
}