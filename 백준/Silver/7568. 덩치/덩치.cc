#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solution()
{
	vector < pair <int, int> > v;
	int n;
	int x, y;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back({ x, y });
	}

	for (int i = 0; i < n; i++) {
		int nx = v[i].first;
		int ny = v[i].second;
		int out = 1;

		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			int dx = v[j].first;
			int dy = v[j].second;
			if (nx < dx && ny < dy) out++;
		}
		cout << out << " ";
	}
}

int main()
{
	solution();
}