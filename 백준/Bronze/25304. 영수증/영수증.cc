#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

void solution()
{
	int x, n, a, b;
	cin >> x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		x -= a * b;
	}

	if (x == 0) cout << "Yes";
	else cout << "No";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}