#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int dp[100005] = { 0 };

void solution()
{
	int result = -987654321;
	int n, k, num;
	cin >> n >> k;
	k--;

	for (int i = 1; i <= n; i++) {
		cin >> num;
		dp[i] = dp[i - 1] + num;
	}

	for (int i = 1; i <= n - k; i++) {
		result = max(result, dp[i + k] - dp[i - 1]);
	}

	cout << result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}