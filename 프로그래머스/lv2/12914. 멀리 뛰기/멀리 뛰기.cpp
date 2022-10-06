#include <string>
#include <vector>

using namespace std;

#define MOD 1234567

long long solution(int n) {
    long long answer = 0;

    int dp[2005] = { 0 };
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = ((dp[i - 1] % MOD) + (dp[i - 2] % MOD)) % MOD;
    }

    answer = dp[n];

    return answer;
}