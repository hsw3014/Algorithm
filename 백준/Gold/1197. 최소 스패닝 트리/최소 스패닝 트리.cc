#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <climits>

using namespace std;

int parent[10005];

//2개의 노드와 가중치 구조체
typedef struct entry {
	int from;
	int to;
	int dist;
}entry;

//우선순위 큐 cmp 구조체
struct cmp {
	bool operator()(entry a, entry b) {
		return a.dist > b.dist;
	}
};

//부모찾기
//자기 자신이 부모라면 종료
//재귀적으로 갱신한다.
int find_parent(int node)
{
	if (node == parent[node]) return node;
	return parent[node] = find_parent(parent[node]);
}

priority_queue < entry, vector <entry>, cmp > pq;

void solution()
{
	//크루스칼 알고리즘 사용
	//가장 가중치가 낮은 간선을 연결시도
	//이 때 사이클이 생기면 안된다.
	//따라서 부모체크를 해야함.

	int v, e, from, to, dist;
	int result = 0;

	//모든 노드의 부모는 자기 자신이다.
	for (int i = 1; i <= 10000; i++) {
		parent[i] = i;
	}

	cin >> v >> e;
	for (int i = 1; i <= e; i++) {
		cin >> from >> to >> dist;
		pq.push({ from, to, dist });
	}

	while (!pq.empty()) {
		int now_from = pq.top().from;
		int now_to = pq.top().to;
		int now_dist = pq.top().dist;

		pq.pop();

		int now_parent_from = find_parent(now_from);
		int now_parent_to = find_parent(now_to);

		//둘의 부모가 같다면 연결할 수 없다.
		//부모가 다르면 연결 후 부모 변경
		if (now_parent_from != now_parent_to) {
			result += now_dist;
			parent[now_parent_from] = now_parent_to;
		}
	}

	cout << result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}