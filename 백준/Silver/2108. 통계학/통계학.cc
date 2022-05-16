#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

#define border 4000

bool compare(const pair <int, int> &a, const pair <int, int> &b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;

}

void solution()
{
	int n, num;
	int les, ran;
	double sum = 0;
	int mn = 4005;
	int mx = -4005;
	vector < int > v;
	int cnt[8005] = { 0 };
	map < int, int > m;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);	//중앙값을 구하기 위한 벡터

		++cnt[num + border];		//최빈값 카운트
		m.erase(num);
		m.insert({ num, cnt[num + border] });

		sum += num;	//평균값을 구하기 위한 합

		mx = max(mx, num);	//범위값을 구하기 위한 최대, 최소
		mn = min(mn, num);
	}

	sort(v.begin(), v.end());

	vector < pair <int, int> > vv(m.begin(), m.end());
	sort(vv.begin(), vv.end(), compare);

	cout << (int)round(sum / n) << '\n';
	cout << v[(n - 1) / 2] << '\n';
	if (vv.size() > 1 && vv[0].second == vv[1].second)
		cout << vv[1].first << '\n';
	else
		cout << vv[0].first << '\n';
	cout << mx - mn;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}