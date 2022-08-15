#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string>

using namespace std;

int arr[305][305];
int n, m, r;

void solution()
{
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int tn = n;
	int tm = m;
	int sx = 0;
	int sy = 0;

	//한번에 r번 회전시키며 내부로 진입
	while (tn > 0 && tm > 0) {
		//r번 회전
		for (int k = 0; k < r; k++) {
			int save = arr[sx][sy];
			//역시계방향으로 돌림 - 처리는 시계방향으로
			for (int j = 0; j < tm - 1; j++) {
				arr[sx][sy + j] = arr[sx][sy + j + 1];
			}
			for (int i = 0; i < tn - 1; i++) {
				arr[sx + i][sy + tm - 1] = arr[sx + i + 1][sy + tm - 1];
			}
			for (int j = 0; j < tm - 1; j++) {
				arr[sx + tn - 1][sy + tm - 1 - j] = arr[sx + tn - 1][sy + tm - 1 - j - 1];
			}
			for (int i = 0; i < tn - 1; i++) {
				arr[sx + tn - 1 - i][sy] = arr[sx + tn - 1 - i - 1][sy];
			}

			//마지막 예외처리
			arr[sx + 1][sy] = save;
		}
		tn -= 2; tm -= 2;
		sx++; sy++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}