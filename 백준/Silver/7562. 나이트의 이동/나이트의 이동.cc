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

	int t;
	int n, x1, y1, x2, y2;
	int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
	int dy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };

	cin >> t;
	for (int i = 0; i < t; i++) {
		bool visit[305][305];
		cin >> n;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				visit[j][k] = false;
			}
		}
		cin >> x1 >> y1;
		cin >> x2 >> y2;

		bool out = false;
		int cnt = 0;
		queue <p> q;
		q.push({ x1, y1 });

		//bfs
		while (!q.empty()) {
			if (out) break;
			int size = q.size();
			cnt++;
			for (int j = 0; j < size; j++) {
				if (out) break;
				int now_x = q.front().first;
				int now_y = q.front().second;
				q.pop();

				//시작점이 도착점
				if (now_x == x2 && now_y == y2) {
					cout << cnt - 1 << '\n';
					out = true;
					break;
				}

				for (int k = 0; k < 8; k++) {
					int nx = now_x + dx[k];
					int ny = now_y + dy[k];

					//예외
					if (nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;

					//도착
					if (nx == x2 && ny == y2) {
						cout << cnt << '\n';
						out = true;
						break;
					}

					if (visit[nx][ny] == false) {
						visit[nx][ny] = true;
						q.push({ nx, ny });
					}
				}
			}
		}
	}
}

int main()
{
	solution();
}