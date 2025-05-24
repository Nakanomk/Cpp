#include <bits/stdc++.h>
using namespace std;

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
			result[i][j] = sum % 998244353;
		}
	}
}

void QuickMatrixMultiply(long long A[3][3], long long power, long long result[3][3])
{
	long long temp1[3][3];
	MatrixCopy(A, temp1);
	long long temp2[3][3] = {0};
	long long output[3][3];
	long long unit[3][3] = {0};
	for (int i = 0; i < 3; i++)
		unit[i][i] = 1;
	while (power)
	{
		if (power & 1)
		{
			MatrixMultiply(unit, temp1, output);
			MatrixCopy(output, unit);
		}
		MatrixMultiply(temp1, temp1, temp2);
		MatrixCopy(temp2, temp1);
		power >>= 1;
	}
	MatrixCopy(output, result);
}

int main(void)
{
	cin >> n;
	cin >> s[0] >> s[1];
	cin >> a >> b >> c;
	long long result[3][3] = {0};
	long long M[3][3] = {{a, b, 1}, {1, 0, 0}, {0, 0, 1}};
	long long F[3][3] = {{s[1], 0, 0}, {s[0], 0, 0}, {c, 0, 0}};
	if (n <= 2)
	{
		cout << s[n - 1];
		system("pause");
		exit(0);
	}
	QuickMatrixMultiply(M, n - 2, result);
	MatrixCopy(result, M);
	MatrixMultiply(M, F, result);

	cout << result[0][0] % 998244353;
	system("pause");
	return 0;
}