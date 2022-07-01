#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

void solution()
{
	vector <int> v;
	int n, m, num;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	for (int i = 0; i < m; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	int size = v.size();
	for (int i = 0; i < size; i++) {
		cout << v[i] << " ";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}