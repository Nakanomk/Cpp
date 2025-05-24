#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
long long s[2];
long long n, a, b, c;

void MatrixCopy(long long OriMatrix[3][3], long long TargetMatrix[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			TargetMatrix[i][j] = OriMatrix[i][j];
	}
}

void MatrixMultiply(long long A[3][3], long long B[3][3], long long result[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			long long sum = 0;
			for (int k = 0; k < 3; k++)
				sum += A[i][k] * B[k][j];
			result[i][j] = sum % MOD;
		}
	}
}

void QuickMatrixPower(long long A[3][3], long long power, long long result[3][3])
{
	long long temp[3][3];
	MatrixCopy(A, temp);
	long long res[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}; // 初始化为单位矩阵

	while (power > 0)
	{
		if (power % 2 == 1)
		{
			long long tempMul[3][3];
			MatrixMultiply(res, temp, tempMul);
			MatrixCopy(tempMul, res);
		}
		long long tempSq[3][3];
		MatrixMultiply(temp, temp, tempSq);
		MatrixCopy(tempSq, temp);
		power /= 2;
	}
	MatrixCopy(res, result);
}

int main(void)
{
	cin >> n;
	cin >> s[0] >> s[1];
	cin >> a >> b >> c;
	n -= 1;
	if (n == 0)
	{
		cout << s[0] % MOD;
		return 0;
	}
	if (n == 1)
	{
		cout << s[1] % MOD;
		return 0;
	}

	long long M[3][3] = {{a, b, 1}, {1, 0, 0}, {0, 0, 1}};
	long long F[3][3] = {{s[1], 0, 0}, {s[0], 0, 0}, {c, 0, 0}};

	long long poweredM[3][3];
	QuickMatrixPower(M, n - 1, poweredM); // 计算M^(n-1)

	long long result[3][3];
	MatrixMultiply(poweredM, F, result);

	cout << result[0][0] % MOD;

	return 0;
}