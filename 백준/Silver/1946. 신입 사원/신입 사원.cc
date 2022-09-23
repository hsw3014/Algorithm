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

#define p pair <int, int>

//서류점수로 오름차순
bool cmp(p p1, p p2) {
	return p1.first < p2.first;
}

void solution()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t, n, a, b;
	cin >> t;

	for (int i = 0; i < t; i++) {
		vector <p> v;
		int ans = 0;

		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> a >> b;
			v.push_back({ a, b });
		}

		//서류순위 기준 오름차순
		sort(v.begin(), v.end(), cmp);

		int rank = v[0].second;
		for (int j = 0; j < n; j++) {
			//면접 순위가 낮아야 채용
			if (rank >= v[j].second) {
				rank = v[j].second;
				ans++;
			}
		}

		cout << ans << '\n';
	}

	
}

int main()
{
	solution();
}