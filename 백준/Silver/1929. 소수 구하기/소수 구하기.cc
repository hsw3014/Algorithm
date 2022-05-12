#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int arr[1000005] = { 0 };

void solution()
{
	int m, n;
	int mid = sqrt(1000000);

	for (int i = 2; i <= 1000000; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= mid; i++) {
		if (arr[i] == 0) continue;
		for (int j = i * i; j <= 1000000; j += i) {
			arr[j] = 0;
		}
	}

	cin >> m >> n;
	for (int i = m; i <= n; i++) {
		if (arr[i] != 0) {
			cout << arr[i] << '\n';
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}