#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void solution()
{
	long long r = 0, n;
	for (int i = 0; i < 5; i++) {
		cin >> n;
		r += (n * n);
	}
	cout << r % 10;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}