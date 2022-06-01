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
	if (v.size() == m) {
		for (int i = 0; i < m; i++) {
			cout << v[i] << " ";
		}
		cout << '\n';
		return;
	}

	//백트래킹
	for (int i = cnt; i <= n; i++) {
		if (true) {
			visit[i] = 1;
			v.push_back(i);
			backtrack(i);
			visit[i] = 0;
			v.pop_back();
		}
	}
}

void solution()
{
	cin >> n >> m;

	backtrack(1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}