#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int dp[105];

void solution()
{
	int n, m, num;
	int result = -105;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		dp[i] = dp[i - 1] + num;
	}

	m--;
	for (int i = 1; i <= n - m; i++) {
		result = max(result, dp[i + m] - dp[i - 1]);
	}

	cout << result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}