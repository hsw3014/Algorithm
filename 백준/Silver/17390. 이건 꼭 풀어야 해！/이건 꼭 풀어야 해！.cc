#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int dp[300005] = { 0 };
vector <int> v;

void solution()
{
	int n, q, num, l, r;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		v.push_back(num);
	}

	//비내림차순 정렬
	sort(v.begin(), v.end());

	int size = v.size();
	for (int i = 1; i <= size; i++) {
		dp[i] = dp[i - 1] + v[i - 1];
	}

	for (int i = 1; i <= q; i++) {
		cin >> l >> r;
		cout << dp[r] - dp[l - 1] << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}