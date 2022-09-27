#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <stack>

using namespace std;

vector <int> v;

void solution()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, num;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end(), greater<>());

	for (int i = 0; i < n; i++) {
		cout << v[i] << '\n';
	}
}

int main()
{
	solution();
}