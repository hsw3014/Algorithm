#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <climits>

using namespace std;

int r, c;
int result = 0;
bool visit[25][25] = { 0 };
char board[25][25] = { 0 };
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void backtrack(int x, int y, unsigned long long mask, int cnt)
{
	result = max(result, cnt);
	int nx, ny;
	//4방향 탐색
	for (int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];

		//테두리 예외처리
		if (nx < 1 || nx > r || ny < 1 || ny > c) continue;

		//다음 방문할 알파벳과 마스크처리
		char next = board[nx][ny];
		bool check = mask & ((unsigned long long)1 << (next - 'A'));

		//마스크에 이번에 방문할 문자와 & 연산시 0이라면 방문 가능
		//1. 해당 위치 방문한 적이 없는가?
		//2. 마스크에 다음에 방문할 알파벳이 들어올 수 있는가?(방문한 적 없는 알파벳)
		if (!visit[nx][ny] && check == 0) {
			visit[nx][ny] = true;
			mask |= ((unsigned long long)1 << (next - 'A'));
			backtrack(nx, ny, mask, cnt + 1);
			visit[nx][ny] = false;
			mask &= ~((unsigned long long)1 << (next - 'A'));
		}
	}
}

void solution()
{
	unsigned long long mask = 0;
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> board[i][j];
		}
	}

	//좌측 상단에서 출발(좌측 상단에서 시작한 것도 말이 지나간것으로 카운트)
	//백트래킹과 비트마스킹 활용
	//비트마스킹으로 이전 방문알파벳 추정 가능
	visit[1][1] = true;
	mask |= ((unsigned long long)1 << (board[1][1] - 'A'));
	backtrack(1, 1, mask, 1);

	cout << result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}