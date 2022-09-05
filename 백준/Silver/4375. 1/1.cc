#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <set>

using namespace std;

int n;

void solution()
{
	while (cin >> n) {
		unsigned long long num = 1;
		int res = 1;

		while (num % n != 0) {
			num %= n;
			num = num * 10 + 1;
			res++;
		}

		cout << res << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}