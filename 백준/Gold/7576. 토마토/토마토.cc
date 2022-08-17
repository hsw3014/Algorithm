#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string>

using namespace std;

#define p pair <int, int>

queue <p> q;
int n, m;
int arr[1005][1005];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int tmt;

void solution()
{
	cin >> m >> n;
	int res = 0;

	//모두 빈판으로(사방을 막아야함)
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			arr[i][j] = -1;
		}
	}

	//상자 채우기, 토마토 큐에 넣기, 안익은 토마토 수 기록
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) tmt++;
			else if (arr[i][j] == 1) q.push({ i, j });
		}
	}

	//날짜계산 시작
	while (true) {
		int size = q.size();
		if (size == 0 || tmt == 0) break;	//탐색불가능, 혹은 다 익었음

		//토마토 익음
		for(int k = 0; k < size; k++) {
			int now_x = q.front().first;
			int now_y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = now_x + dx[i];
				int ny = now_y + dy[i];

				//안익은 토마토면 익게하고 큐에 넣는다. 그외에는 진행X
				if (arr[nx][ny] == 0) {
					arr[nx][ny] = 1;
					q.push({ nx, ny });
					tmt--;
				}
			}
		}

		//토마토가 익은 날짜
		res++;
	}

	//다 익지 못할 경우
	if (tmt > 0) res = -1;

	cout << res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}