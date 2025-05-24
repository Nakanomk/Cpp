#include<bits/stdc++.h>
#define DEBUG
#define ll long long

using namespace std;

//Variables
int m, n;
vector<vector<int>> Chess(100,vector<int>(100,2)), visited(100,vector<int>(100,0));
int record = 2147483647;
//Fun
int read() {
	int x = 0, w = 1; char ch;
	while(!isdigit(ch = getchar())) if(ch == '-') w = -w;
	while(isdigit(ch)) {
		x = 10 * x + ch - '0';
		ch = getchar();
	}
	return x * w;
}

bool isInside(int x, int y) {
	return (x >= 1 && x <= m && y >= 1 && y <= m);
}

void dfs(int x, int y, int cnt, int color) {
	if(x == m && y == m) {
		record = cnt; return;
	}
	if(cnt >= record) {
		if(color != 2) Chess[x-1][y-1] = 2; return;
	}
	visited[x-1][y-1] = 1;
	if(isInside(x-1, y) && visited[x-2][y-1] == 0) {
		if(Chess[x-2][y-1] == 2 && color == 2) {
			Chess[x-2][y-1] = 0;
			dfs(x-1, y, cnt + 2 + (Chess[x-2][y-1] != Chess[x-1][y-1]), 0);
			Chess[x-2][y-1] = 1;
			dfs(x-1, y, cnt + 2 + (Chess[x-2][y-1] != Chess[x-1][y-1]), 1);
		}
		else if(Chess[x-2][y-1] == 2 && color != 2);
		else dfs(x-1, y, cnt + (Chess[x-2][y-1] != Chess[x-1][y-1]), 2);
	}
	if(isInside(x+1, y) && visited[x][y-1] == 0) {
		if(Chess[x][y-1] == 2 && color == 2) {
			Chess[x][y-1] = 0;
			dfs(x+1, y, cnt + 2 + (Chess[x][y-1] != Chess[x-1][y-1]), 0);
			Chess[x][y-1] = 1;
			dfs(x+1, y, cnt + 2 + (Chess[x][y-1] != Chess[x-1][y-1]), 1);
		}
		else if(Chess[x][y-1] == 2 && color != 2);
		else dfs(x+1, y, cnt + (Chess[x][y-1] != Chess[x-1][y-1]), 2);
	}
	if(isInside(x, y-1) && visited[x-1][y-2] == 0) {
		if(Chess[x-1][y-2] == 2 && color == 2) {
			Chess[x-1][y-2] = 0;
			dfs(x, y-1, cnt + 2 + (Chess[x-1][y-2] != Chess[x-1][y-1]), 0);
			Chess[x-1][y-2] = 1;
			dfs(x, y-1, cnt + 2 + (Chess[x-1][y-2] != Chess[x-1][y-1]), 1);
		}
		else if(Chess[x-1][y-2] == 2 && color != 2);
		else dfs(x, y-1, cnt + (Chess[x-1][y-2] != Chess[x-1][y-1]), 2);
	}
	if(isInside(x, y+1) && visited[x-1][y] == 0) {
		if(Chess[x-1][y] == 2 && color == 2) {
			Chess[x-1][y] = 0;
			dfs(x, y+1, cnt + 2 + (Chess[x-1][y] != Chess[x-1][y-1]), 0);
			Chess[x-1][y] = 1;
			dfs(x, y+1, cnt + 2 + (Chess[x-1][y] != Chess[x-1][y-1]), 1);
		}
		else if(Chess[x-1][y] == 2 && color != 2);
		else dfs(x, y+1, cnt + (Chess[x-1][y] != Chess[x-1][y-1]), 2);
	}
	if(color != 2) Chess[x-1][y-1] = 2;
	visited[x-1][y-1] = 0;
}

int main() {
	m = read(); n = read();
	for(int i = 0; i < n; i++) {
		int x = read(), y = read(), c = read();
		Chess[x-1][y-1] = c;
	}

	dfs(1,1,0,2);
	if(record == 2147483647) record = -1;
	cout << record;
	return 0;
}