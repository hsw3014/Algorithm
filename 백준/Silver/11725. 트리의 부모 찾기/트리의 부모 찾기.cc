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

int n;
vector <int> v[100005];
bool visit[100005] = { false };
int res[100005] = { 0 };

void solution()
{
	int from, to;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> from >> to;
		//트리 양방향 연결
		v[from].push_back(to);
		v[to].push_back(from);
	}

	queue <int> q;
	q.push(1);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		//루트부터 내려가며 채우기
		int size = v[now].size();
		for (int i = 0; i < size; i++) {
			int next = v[now][i];

			//중복하지 않도록 진행
			if (visit[next] == false) {
				visit[next] = true;
				q.push(next);

				//next의 부모는 now노드
				res[next] = now;
			}
		}
	}

	//출력
	for (int i = 2; i <= n; i++) {
		cout << res[i] << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}