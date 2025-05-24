#include <bits/stdc++.h>
#define DEBUG
#define ll long long

using namespace std;

int m, n, x, y, c, ans = 1e9, val[101][101][5], num[101][101];
int xy[4][2]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool vis[101][101];

void dfs(int x, int y, int now, int lst) {
	if (now > ans)
		return;
	if (x == m && y == m) {
		ans = min(ans, now);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int dx = x + xy[i][0], dy = y + xy[i][1];
		if (dx >= 1 && dx <= m && dy >= 1 && dy <= m && vis[dx][dy] == 0 && (num[x][y] != -1 || num[dx][dy] != -1)) {
			if (num[dx][dy] == -1) {
				if (now + 2 < val[dx][dy][num[dx][dy]+1]) {
					vis[dx][dy] = 1;
					val[dx][dy][num[dx][dy]+1] = now + 2;
					dfs(dx, dy, now + 2, lst);
					vis[dx][dy] = 0;
				}
			}
			else {
				if (num[dx][dy] == lst) {
					if (now < val[dx][dy][num[dx][dy]+1]) {
						vis[dx][dy] = 1;
						val[dx][dy][num[dx][dy]+1] = now;
						dfs(dx, dy, now, lst);
						vis[dx][dy] = 0;
					}
				}
				else {
					if (now + 1 < val[dx][dy][num[dx][dy]+1]) {
						vis[dx][dy] = 1;
						val[dx][dy][num[dx][dy] + 1] = now + 1;
						dfs(dx, dy, now + 1, num[dx][dy]);
						vis[dx][dy] = 0;
					}
				}
			}
		}
	}
}

int main() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			num[i][j] = -1;
			for(int k = 0; k <= 2; k++) val[i][j][k] = 1e9;
		}
	}
	while (n--) {
		cin >> x >> y >> c;
		num[x][y] = c;
	}
	vis[1][1] = 1;
	for(int k = 0; k <= 2; k++) val[1][1][k] = 0;
	dfs(1, 1, 0, num[1][1]);
	if (ans == 1e9) ans = -1;
	cout << ans;
	return 0;
}