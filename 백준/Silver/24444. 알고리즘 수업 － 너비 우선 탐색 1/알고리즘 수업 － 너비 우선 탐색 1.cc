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

void bfs(vector < vector <int> > v, int r)
{
	//방문초기화
	int visit[100005];
	int cnt = 1;
	int size = v.size();
	for (int i = 0; i < size; i++) {
		visit[i] = 0;
	}

	//시작노드
	visit[r] = cnt++;

	queue <int> q;
	q.push(r);

	//bfs 시작
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		int s = v[now].size();
		for (auto it : v[now]) {
			if (visit[it] == 0) {
				visit[it] = cnt++;
				q.push(it);
			}
		}
	}

	for (int i = 1; i < size; i++) {
		cout << visit[i] << '\n';
	}
}

void solution()
{
	int n, m, r;
	int from, to;

	cin >> n >> m >> r;

	vector < vector <int> > v;
	v.resize(n + 1);	//n + 1개의 노드 갖도록 리사이즈

	//양방향 간선
	for (int i = 0; i < m; i++) {
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	//정렬
	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}

	bfs(v, r);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}