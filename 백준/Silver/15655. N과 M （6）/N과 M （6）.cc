#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <map>

using namespace std;

int n, m;
vector <int> v;
vector <int> r;

void backtrack(int idx)
{
	int size = r.size();
	if (size == m) {
		for (int i = 0; i < size; i++) {
			cout << r[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = idx + 1; i < n; i++) {
		r.push_back(v[i]);
		backtrack(i);
		r.pop_back();
	}
}

void solution()
{
	int num;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	int size = v.size();

	for (int i = 0; i < size; i++) {
		r.push_back(v[i]);
		backtrack(i);
		r.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}