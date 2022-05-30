#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
bool visit[10] = { 0 };
vector <int> v;

void backtrack(int cnt)
{
	//다 채웠으면 출력
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << v[i] << " ";
		}
		cout << '\n';
		return;
	}

	//백트래킹
	for (int i = 1; i <= n; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			v.push_back(i);
			backtrack(v.size());
			visit[i] = 0;
			v.pop_back();
		}
	}
}

void solution()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			v.push_back(i);
			backtrack(v.size());
			visit[i] = 0;
			v.pop_back();
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}