#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define p pair <int, int>
#define MAX 2e9

int dp(const vector <p> &v, const int &k, const int c, int idx, int sum)
{
	//인덱스 초과시 배제
	if (idx > v.size()) return MAX;
	//끝에 도달
	if (idx == v.size()) return sum;
	//매우 큰 점프 조건
	if (c > 0) {
		return min({ dp(v, k, 0, idx + 3, sum + k), dp(v, k, c, idx + 1, sum + v[idx].first), dp(v, k, c, idx + 2, sum + v[idx].second) });
	}
	else {
		return min({ dp(v, k, c, idx + 1, sum + v[idx].first), dp(v, k, c, idx + 2, sum + v[idx].second) });
	}
}

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	vector <p> v;
	int n, a, b, k;

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	cin >> k;

	return dp(v, k, 1, 0, 0);
}

int main()
{
	cout << solution();
}

