#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

int n, m;
long long dp[40];

long long dfs(int x)
{
	if (x > 35) return 0;

	if (dp[x] != 0) return dp[x];

	for (int i = 0; i < x; i++) {
		dp[x] += dfs(i) * dfs(x - i - 1);
	}
	return dp[x];
}

void solve()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	dp[0] = 1;
	for (int i = 1; i <= 35; i++) {
		dfs(i);
	}

	cin >> n;

	cout << dp[n];
}

int main()
{
	solve();
}