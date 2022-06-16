#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int dp[100005];

void solution()
{
	int n, m, num, a, b;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		dp[i] = dp[i - 1] + num;
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
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