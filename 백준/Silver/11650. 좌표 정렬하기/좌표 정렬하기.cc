#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

bool cmp(const pair <int, int>& a, const pair <int, int>& b)
{
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

void solution()
{
	int n, a, b;
	vector < pair < int, int > > v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a, b });
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << v[i].first << " " << v[i].second << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}