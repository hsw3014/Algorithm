#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <climits>

using namespace std;

int dp[105];	//idx위치에 있을 때 x의 횟수로 이동하였음
int board[105] = { 0 };	//사다리와 뱀 정보 가짐

void solution()
{
	queue <int> q;
	int n, m, from, to;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> from >> to;
		board[from] = to;
	}

	for (int i = 0; i < m; i++) {
		cin >> from >> to;
		board[from] = to;
	}

	//방문여부체크 및 최소 굴린 횟수
	for (int i = 1; i <= 100; i++) {
		dp[i] = -1;
	}

	//1번칸에서 출발한다.
	q.push(1);
	dp[1] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 1; i <= 6; i++) {
			int next = now + i; //다음 위치
			if (next > 100) continue;	//100넘어가면 더 할 필요 없음

			//사다리나 뱀 있으면 목적지 변경
			if (board[next] != 0) next = board[next];

			//방문한 적 없으면 새로 갱신
			if (dp[next] == -1) {
				dp[next] = dp[now] + 1;
				q.push(next);
			}
		}
	}

	cout << dp[100];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}