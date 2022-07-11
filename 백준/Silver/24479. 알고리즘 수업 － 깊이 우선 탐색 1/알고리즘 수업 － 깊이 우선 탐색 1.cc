#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <climits>

using namespace std;

int cnt;
int result[100005] = { 0 };
bool visit[100005] = { 0 };
vector <int> v[100005];

void dfs(int now)
{
	visit[now] = true;
	result[now] = cnt++;

	//현재 위치 노드의 집합을 auto로 추론
	for (auto node_set : v[now]) {
		if (visit[node_set] == 0) {
			dfs(node_set);
		}
	}
}

void solution()
{
	int n, m, r, from, to;
	cin >> n >> m >> r;

	cnt = 1;
	//정렬된 상태로 연결
	//양방향 주의
	for (int i = 0; i < m; i++) {
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	//각 간선들 오름차순으로 정렬
	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}

	dfs(r);

	for (int i = 1; i <= n; i++) {
		cout << result[i] << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}