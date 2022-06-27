#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void solution()
{
	char arr[105][205];
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = n - i - 1; j <= n + i - 1; j++) {
			arr[i][j] = '*';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + i; j++) {
			if (arr[i][j] != '*') cout << " ";
			else cout << arr[i][j];
		}
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}