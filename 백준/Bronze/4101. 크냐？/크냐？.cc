#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void solution()
{
	int a, b;
	while (true) {
		cin >> a >> b;
		if (a == 0 && b == 0) break;
		(a > b) ? (cout << "Yes\n") : (cout << "No\n");
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}