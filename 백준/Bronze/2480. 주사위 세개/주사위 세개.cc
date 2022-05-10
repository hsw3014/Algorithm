#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void solution()
{
	vector <int> v;
	int a, b, c;
	cin >> a >> b >> c;
	v.push_back(a); v.push_back(b); v.push_back(c);
	if (a == b && b == c) {
		cout << 10000 + a * 1000;
	}
	else if (a != b && b != c && c != a) {
		cout << max({ a, b, c }) * 100;
	}
	else {
		sort(v.begin(), v.end());
		cout << 1000 + v[1] * 100;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}