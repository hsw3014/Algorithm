#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int arr[250005] = { 0 };

void solution()
{
	int n, answer;

	//본인값 가짐, 0이면 소수아님
	for (int i = 2; i <= 250000; i++) {
		arr[i] = i;
	}

	//소수 판별
	for (int i = 2; i <= 500; i++) {
		if (arr[i] == 0) continue;
		for (int j = i * i; j <= 250000; j += i) {
			arr[j] = 0;
		}
	}

	while (true) {
		cin >> n;
		answer = 0;
		if (n == 0) break;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (arr[i] != 0) answer++;
		}
		cout << answer << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}