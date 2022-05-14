#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>

using namespace std;

void solution()
{
	int n, a;
	int cnt[10005] = { 0 };
	cin >> n;
	map <int, int> m;

	for (int i = 0; i < n; i++) {
		cin >> a;
		m.insert({ a, a });	//중복제거 되는 맵
		cnt[a]++;	//개수 기록
	}

	vector < pair <int, int> > v(m.begin(), m.end());	//맵을 벡터에 넣고 정렬
	sort(v.begin(), v.end());
	int size = v.size();
	for (int i = 0; i < size; i++) {
		int now = cnt[v[i].first];
		for (int j = 0; j < now; j++) {
			cout << v[i].first << '\n';
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}