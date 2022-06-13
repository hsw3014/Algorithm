#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

long long dp[1000005];
long long rest_cnt[1005];

void solution()
{
	int n, m, num;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> num;
		dp[i] = dp[i - 1] + num;	//누적합
		rest_cnt[dp[i] % m]++;	//누적합의 나머지 카운팅
	}

	//누적합의 역할 -> dp[A]와 dp[B]의 나머지가 동일하면, A+1 ~ B 구간합은 M으로 나눠떨어진다.

	long long answer = rest_cnt[0];	//나머지가 0인건 자체적으로 성립함
	for (int i = 0; i < m; i++) {
		answer += rest_cnt[i] * (rest_cnt[i] - 1) / 2;
	}

	cout << answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}