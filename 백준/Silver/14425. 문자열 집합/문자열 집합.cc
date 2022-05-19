#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

void solution()
{
	int n, m;
	int answer = 0;
	string str;
	map < string, int > mp;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str;
		mp.insert({ str, 1 });
	}

	for (int i = 0; i < m; i++) {
		string now;
		cin >> now;
		if (mp[now] == 1) answer++;
	}

	cout << answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}