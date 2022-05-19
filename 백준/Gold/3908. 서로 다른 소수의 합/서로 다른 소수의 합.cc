#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

const int MAX_N = 1120;
const int MAX_K = 14;
int T, n, k;
bool prime[MAX_N + 5] = { 0 };
int dp[MAX_N+5][MAX_K + 1] = { 0 };	//i를 j개로 만드는 경우

vector <int> p;

void eratose()
{
	int point = sqrt(MAX_N);
	for (int i = 2; i <= point; i++) {
		if (prime[i] == false) {
			for (int j = i * i; j <= MAX_N; j += i) {
				prime[j] = true;
			}
		}
	}

	for (int i = 2; i <= MAX_N; i++) {
		if (prime[i] == false)
			p.push_back(i);
	}
}

void solve()
{
	int now;
	int size = p.size();
	dp[0][0] = 1;

	for (int i = 0; i < size; i++) {
		now = p[i];
		for (int j = MAX_N; j >= now; j--) {
			for (int k = 1; k <= MAX_K; k++)
				dp[j][k] += dp[j - now][k - 1];
		}
	}
}

int main()
{
	cin >> T;

	eratose();
	solve();

	for (int i = 0; i < T; i++) {
		cin >> n >> k;
		printf("%d\n", dp[n][k]);
	}
}