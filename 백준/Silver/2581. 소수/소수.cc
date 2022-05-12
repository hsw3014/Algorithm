#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int arr[10005] = { 0 };

void solution()
{
	int m, n;
	int answer = 0;
	int mn = 10001;

	for (int i = 2; i <= 10000; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= 100; i++) {
		if (arr[i] == 0) continue;
		for (int j = i * i; j <= 10000; j += i) {
			arr[j] = 0;
		}
	}

	cin >> m >> n;
	for (int i = m; i <= n; i++) {
		if (arr[i] != 0) {
			answer += arr[i];
			mn = min(mn, arr[i]);
		}
	}

	if (answer == 0) cout << "-1";
	else cout << answer << endl << mn;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}