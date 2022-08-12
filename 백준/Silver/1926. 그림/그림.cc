#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string>

using namespace std;

bool visit[505][505] = { 0 };
int arr[505][505] = { 0 };
int n, m;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int max_sz = 0;
int many = 0;

int dfs(int x, int y)
{
	//방문한 적이 있었다면 방문하지않음
	if (visit[x][y] == true) return 0;
	visit[x][y] = true;
	int ret = 0;

	//그림 존재
	if (arr[x][y] == 1) {
		ret = 1;	//자기 위치 최소1개
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			ret += dfs(nx, ny);
		}
	}

	return ret;
}

void solution()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			//dfs 시작점
			if (visit[i][j] == false && arr[i][j] == 1) {
				int s = dfs(i, j);
				many++;
				max_sz = max(s, max_sz);
			}
		}
	}

	cout << many << '\n' << max_sz;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}