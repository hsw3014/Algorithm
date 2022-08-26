#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <map>

using namespace std;

void solution()
{
	vector <int> v;
	int st = 1;
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= i; j++) {
			v.push_back(i);
		}
		if (v.size() > 1000) break;
	}

	int n, m;
	cin >> n >> m;

	int res = 0;
	for (int i = n - 1; i <= m - 1; i++) {
		res += v[i];
	}

	cout << res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}