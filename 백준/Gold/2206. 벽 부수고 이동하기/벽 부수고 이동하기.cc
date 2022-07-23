//#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef struct entry {
	int x;
	int y;
	int skill;
}entry;

int n, m;
int dp[1005][1005][2] = { 0 };
int board[1005][1005];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
queue < entry > q;

void solve()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0); cout.tie(0);
	for (int i = 0; i <= n+1; i++) {
		for (int j = 0; j <= m+1; j++) {
			board[i][j] = 1;
		}
	}

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &board[i][j]);
		}
	}

	q.push({ 1,1,1 });
	dp[1][1][0] = 1;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int sp = q.front().skill;

		if (x == n && y == m) {
			printf("%d", dp[x][y][sp] + 1);
			break;
		}

		q.pop();

		if (x < 1 || x > n || y < 1 || y > m) continue;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (board[nx][ny] == 1) {
				if (sp == 1) {
					dp[nx][ny][sp - 1] = dp[x][y][sp] + 1;
					q.push({ nx, ny, sp - 1 });
				}
			}
			else {
				if (dp[nx][ny][sp] == 0) {
					dp[nx][ny][sp] = dp[x][y][sp] + 1;
					q.push({ nx, ny, sp});
				}
			}
		}
	}

	if (q.empty()) printf("-1");
}

int main()
{
	solve();
}