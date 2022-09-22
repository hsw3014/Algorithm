#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <stack>

using namespace std;

int arr[2200][2200] = { 0 };
int cnt_1 = 0;
int cnt_2 = 0;
int cnt_3 = 0;

void dfs(int x, int y, int l) {
	int start = arr[x][y];
	if (l == 1) {
		if (start == 1) cnt_1++;
		else if (start == 2) cnt_2++;
		else if (start == 3) cnt_3++;
		return;
	}

	bool check = false;
	for (int i = x; i < x + l; i++) {
		if (check) break;
		for (int j = y; j < y + l; j++) {
			if (start != arr[i][j]) check = true;
		}
	}

	//유효체크
	if (check) {
		int next = l / 3;
		dfs(x, y, next);
		dfs(x, y + next, next);
		dfs(x, y + next + next, next);
		dfs(x + next, y, next);
		dfs(x + next, y + next, next);
		dfs(x + next, y + next + next, next);
		dfs(x + next + next, y, next);
		dfs(x + next + next, y + next, next);
		dfs(x + next + next, y + next + next, next);
	}
	else {
		if (start == 1) cnt_1++;
		else if (start == 2) cnt_2++;
		else if (start == 3) cnt_3++;
	}
}

void solution()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, num;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> num;
			if (num == -1) arr[i][j] = 1;
			if (num == 0) arr[i][j] = 2;
			if (num == 1) arr[i][j] = 3;
		}
	}

	dfs(1, 1, n);

	cout << cnt_1 << '\n' << cnt_2 << '\n' << cnt_3 << '\n';
}

int main()
{
	solution();
}