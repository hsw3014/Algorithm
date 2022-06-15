#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

long long arr[100005];
long long dp[100005];

void solution()
{
	long long result = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = dp[i - 1] + arr[i];
	}

	//임의의 두 정수를 뽑아 모든 경우의 두 수의 곱을 구해야 함.
	//부분합을 구하고, 가장 왼쪽부터 하나의 피벗을 지정
	//해당 피벗의 바로 다음수 부터 끝까지의 누적합과 피벗을 곱한다.
	//이를 끝까지 진행하면 모든 경우의 수에 대해 곱을 구한것과 같다.
	for (int i = 1; i <= n; i++) {
		long long part_sum = dp[n] - dp[i];
		result += part_sum * arr[i];
	}

	cout << result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}