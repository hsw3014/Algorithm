#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <stack>

using namespace std;

#define p pair <int, int>

void solution()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	queue <p> q;
	int board[55][55];
	int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
	int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
	int n, m;
	int zcnt = 0;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				q.push({i, j});
			}
			else {
				zcnt++;
			}
		}
	}

	int res = 0;

	while (!q.empty()){
		//모두 상어로 가득찼으면 그 전 거리가 정답
		if (zcnt == 0) {
			cout << res;
			return;
		}

		int sz = q.size();
		res++;

		for(int k = 0; k < sz; k++) {
			int now_x = q.front().first;
			int now_y = q.front().second;
			q.pop();

			for (int i = 0; i < 8; i++) {
				int nx = now_x + dx[i];
				int ny = now_y + dy[i];

				if (nx < 1 || nx > n || ny < 1 || ny > m) continue;

				//상어로 점점 채운다.
				if (board[nx][ny] == 0) {
					board[nx][ny] = 1;
					zcnt--;
					q.push({ nx, ny });
				}
			}
		}
	}
}

int main()
{
	solution();
}