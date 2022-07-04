#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int arr[135][135];
int white, blue;

void dfs(int x1, int y1, int x2, int y2)
{
	int color = arr[x1][y1]; //첫번째 색 기억
	int mid_x = (x1 + x2) / 2;
	int mid_y = (y1 + y2) / 2;
	//1칸남음
	if (x1 == x2) {
		if (color == 0) white++;
		else blue++;
		return;
	}
	else {
		int isSquare = 1;
		for (int i = x1; i <= x2; i++) {
			for (int j = y1; j <= y2; j++) {
				if (color != arr[i][j]) {
					isSquare = 0;
					break;
				}
			}
			if (isSquare == 0) break;
		}

		//사각형 종이 만족
		if (isSquare) {
			if (color == 0) white++;
			else blue++;
			return;
		}
		else {
			//사방 분할
			dfs(x1, y1, mid_x, mid_y);
			dfs(x1, mid_y + 1, mid_x, y2);
			dfs(mid_x + 1, y1, x2, mid_y);
			dfs(mid_x + 1, mid_y + 1, x2, y2);
		}
	}
}

void solution()
{
	//0은 흰색, 1은 파란색
	white = 0; blue = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(1, 1, n, n);
	cout << white << '\n' << blue;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}