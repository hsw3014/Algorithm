#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string>

using namespace std;

#define p pair <int, int>

int arr[55][55] = { 0 };
bool visit[55][55] = { false };
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

queue <p> q;

void solution()
{
	int w, h;
	while (true) {
		int res = 0;
		cin >> w >> h;
		if (w == 0 && h == 0) return;

		//입력
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> arr[i][j];
				visit[i][j] = false;
			}
		}

		//bfs
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (visit[i][j] == false && arr[i][j] == 1) {
					visit[i][j] = true;

					//섬 발견
					res++;
					q.push({ i, j });

					//인근 섬 묶음
					while (!q.empty()) {
						int now_x = q.front().first;
						int now_y = q.front().second;
						q.pop();

						for (int k = 0; k < 8; k++) {
							int nx = now_x + dx[k];
							int ny = now_y + dy[k];

							if (visit[nx][ny] == false && arr[nx][ny] == 1) {
								visit[nx][ny] = true;
								q.push({ nx, ny });
							}
						}
					}
				}
			}
		}

		cout << res << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}