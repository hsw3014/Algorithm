#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int n, m;
vector <int> v;
vector <int> v2;
bool visit[10] = { false };

void backtrack(int depth)
{
	//출력
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << v2[i] << " ";
		}
		cout << '\n';
	}
	else {
		for (int i = 0; i < n; i++) {
			if (visit[i] == false) {
				visit[i] = true;
				v2.push_back(v[i]);
				backtrack(depth + 1);
				visit[i] = false;
				v2.pop_back();
			}
		}
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

	for (int i = 0; i < n; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			v2.push_back(v[i]);
			backtrack(1);
			visit[i] = false;
			v2.pop_back();
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}