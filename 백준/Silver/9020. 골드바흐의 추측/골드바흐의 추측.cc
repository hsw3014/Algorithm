#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int arr[10005] = { 0 };

void solution()
{
	int T, n, a, b;

	//본인값 가짐, 0이면 소수아님
	for (int i = 2; i <= 10000; i++) {
		arr[i] = i;
	}

	//소수 판별
	for (int i = 2; i <= 100; i++) {
		if (arr[i] == 0) continue;
		for (int j = i * i; j <= 10000; j += i) {
			arr[j] = 0;
		}
	}

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		int mid = n / 2;
		for (int i = 2; i <= mid; i++) {
			if (arr[i] != 0 && arr[n - i] != 0) {
				a = i; b = n - i;
			}
		}

		cout << a << " " << b << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}