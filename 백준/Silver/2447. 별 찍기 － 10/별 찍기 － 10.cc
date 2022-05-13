#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

char board[2200][2200];

void dfs(int n, int x1, int y1, int x2, int y2)
{
	if (n == 1) {
		board[x1][y1] = '*';
	}
	else {
		dfs(n / 3, x1, y1, x2 / 3, y2 / 3);
		dfs(n / 3, x1, y1 + (n / 3), x2 / 3, y2 / 3 * 2);
		dfs(n / 3, x1, y1 + (n / 3) * 2, x2 / 3, y2);

		dfs(n / 3, x1 + (n / 3), y1, x2 / 3 * 2, y2 / 3);
		//dfs(n / 3, x1 + (n / 3), y1 + (n / 3), x2 / 3 * 2, y2 / 3 * 2);
		dfs(n / 3, x1 + (n / 3), y1 + (n / 3) * 2, x2 / 3 * 2, y2);

		dfs(n / 3, x1 + (n / 3) * 2, y1, x2, y2 / 3);
		dfs(n / 3, x1 + (n / 3) * 2, y1 + (n / 3), x2, y2 / 3 * 2);
		dfs(n / 3, x1 + (n / 3) * 2, y1 + (n / 3) * 2, x2, y2);
	}
}

void solution()
{
	int n;
	cin >> n;
	dfs(n, 1, 1, n, n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (board[i][j] != '*') board[i][j] = ' ';
			cout << board[i][j];
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