#include<bits/stdc++.h>
using namespace std;

void pow(vector<vector<int>> &M, vector<vector<int>> &B) {
	vector<vector<int>> N(3, vector<int>(3,0));
	vector<vector<int>> T = M;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			for(int k = 0; k < 3; k++)
				if(M[i][k] * B[k][j]) N[i][j] = 1;
	for(int i = 0; i < 9; i++)
		if(T[i/3][i%3]) N[i/3][i%3] = 1;
	M = N;
	return;
}

int main() {
	vector<vector<int>> M(3, vector<int>(3, 0)), N(3, vector<int>(3, 0)), T(3, vector<int>(3, 0));
	int cnt = 0;
	for(int i = 0b000000000; i <= 0b111111111; i++) {
		int k = i;
		for(int j = 0; j < 9; j++) {
			M[j/3][j%3] = k & 1;
			k >>= 1;
		}
		N = M; pow(M, N); pow(M, N);
		if(N == M) cnt++;
	}

	cout << cnt;
	return 0;
}