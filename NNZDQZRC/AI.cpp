#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void MatrixTranspose(vector<vector<ll>> &OriMatrix)
{
	int row = OriMatrix.size();
	int col = OriMatrix[0].size();
	vector<vector<ll>> TempMatrix(row, vector<ll>(col));
	TempMatrix = OriMatrix;
	OriMatrix.clear();
	OriMatrix.resize(col);
	for (int i = 0; i < col; i++)
	{
		OriMatrix[i].resize(row);
	}
	for (int i = 0; i < col; i++)
		for (int j = 0; j < row; j++)
			OriMatrix[i][j] = TempMatrix[j][i];
}

void MatrixMultiply(vector<vector<ll>> &Matrix1, vector<vector<ll>> &Matrix2)
{
	int row = Matrix1.size();
	int col = Matrix2[0].size();
	int col_1 = Matrix1[0].size();
	vector<vector<ll>> TempMatrix(row, vector<ll>(col));
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				ll sum = 0;
				for (int k = 0; k < col_1; k++)
					sum += Matrix1[i][k] * Matrix2[k][j];
				TempMatrix[i][j] = sum;
			}
		}
	}
	Matrix1 = TempMatrix;
}

int main(void)
{
	int n, d;
	cin >> n >> d;
	vector<vector<vector<ll>>> InputMatrix(3, vector<vector<ll>>(n, vector<ll>(d)));
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < d; k++)
			{
				cin >> InputMatrix[i][j][k];
			}
		}
	}
	vector<vector<ll>> W(1, vector<ll>(n));
	for (int i = 0; i < n; i++)
		cin >> W[0][i];
	MatrixTranspose(InputMatrix[1]);
	MatrixMultiply(InputMatrix[1], InputMatrix[2]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < d; j++)
			InputMatrix[0][i][j] *= W[0][i];
	MatrixMultiply(InputMatrix[0], InputMatrix[1]);

	int row = InputMatrix[0].size();
	int col = InputMatrix[0][0].size();
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << InputMatrix[0][i][j] << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}