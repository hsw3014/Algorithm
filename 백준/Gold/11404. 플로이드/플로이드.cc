#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <climits>

using namespace std;

long long dp[105][105];

void solution()
{
	int n, m, from, to;
	long long dist;

	//플로이드 와샬 알고리즘
	//자기 자신은 0, 그외에는 전부 가중치 무한대(못감)
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (i == j) dp[i][j] = 0;
			else dp[i][j] = INT_MAX;
		}
	}

	//시작점과 끝점이 같은 노선이 여러개 제시될 수 있음 -> 최소만 반영
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> from >> to >> dist;
		dp[from][to] = min(dp[from][to], dist);
	}

	//dp[i][j] = dp[i][k] + dp[k][j]; -> i에서 j로 가는 최소 가중치
	//i에서 j로 가는 최소길 = i에서 k로 최소 + k에서 j로
	//즉 k는 거쳐가는 노드
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] == INT_MAX) cout << "0 ";
			else cout << dp[i][j] << " ";
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