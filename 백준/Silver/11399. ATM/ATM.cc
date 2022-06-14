#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void solution()
{
	vector < int > v;
	int n, t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		v.push_back(t);
	}

	sort(v.begin(), v.end());

	int result = 0;
	int st = 0;

	for (int i = 0; i < n; i++) {
		st += v[i];
		result += st;
	}

	cout << result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}