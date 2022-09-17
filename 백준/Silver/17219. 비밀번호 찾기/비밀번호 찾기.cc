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

	int n, m;
	string addr, pw, id;
	map <string, string> map;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> addr >> pw;
		map[addr] = pw;
	}

	for (int i = 0; i < m; i++) {
		cin >> id;
		cout << map[id] << '\n';
	}
}

int main()
{
	solution();
}