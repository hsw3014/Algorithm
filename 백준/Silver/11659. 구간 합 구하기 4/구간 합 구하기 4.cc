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
	int n, k, num;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		dp[i] = dp[i - 1] + num;
	}

	int a, b;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		cout << dp[b] - dp[a - 1] << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}