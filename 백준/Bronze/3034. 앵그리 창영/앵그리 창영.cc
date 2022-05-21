#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <cmath>

using namespace std;

void solution()
{
	int n, a, b, k, diag;
	cin >> n >> a >> b;
	diag = sqrt(a * a + b * b);
	for (int i = 0; i < n; i++) {
		cin >> k;
		if (k <= a || k <= b || k <= diag) cout << "DA\n";
		else cout << "NE\n";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}