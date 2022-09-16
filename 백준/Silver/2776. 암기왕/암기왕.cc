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

void solution()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t, n, m, num;

	cin >> t;

	//입력이 정수 전체범위이므로 배열을 쓰기 어려움
	//해쉬하자
	for (int i = 0; i < t; i++) {
		map <int, bool> map;

		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> num;
			map[num] = true;
		}

		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> num;
			if (map[num] == true) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
	}
}

int main()
{
	solution();
}