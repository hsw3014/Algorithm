#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int arr[10005];
int sum[10005] = { 0 };

void solution()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];	//누적합
	}

	int left = 1, right = 1, subsum = 0, result = 0;
	while (right <= n) {
		subsum = sum[right] - sum[left - 1];
		if (subsum < m) {	//누적합이 작으면 right 증가
			right++;
		}
		else if (subsum > m) {	//누적합 초과해버리면 left 증가
			left++;
		}
		else {	//정확하면 정답증가
			right++;
			result++;
		}
	}

	cout << result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}