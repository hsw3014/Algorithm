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
	int a, b, c;
	while (true) {
		vector <int> v;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) break;
		v.push_back(a); v.push_back(b); v.push_back(c);
		sort(v.begin(), v.end());
		if (v[0] * v[0] + v[1] * v[1] == v[2] * v[2]) cout << "right\n";
		else cout << "wrong\n";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}