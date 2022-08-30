#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <map>

using namespace std;

void solution()
{
	vector <int> hp;
	vector <int> vp;
	vector <int> h_dif;
	vector <int> v_dif;

	int n, m, c, dir, v;
	cin >> m >> n;

	//시작점, 끝점
	hp.push_back(0);
	hp.push_back(m);
	vp.push_back(0);
	vp.push_back(n);

	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> dir >> v;
		if (dir == 0) vp.push_back(v);
		else hp.push_back(v);
	}

	//거리 정렬
	sort(hp.begin(), hp.end());
	sort(vp.begin(), vp.end());

	int v_len = vp.size();
	for (int i = 1; i < v_len; i++) {
		v_dif.push_back(vp[i] - vp[i - 1]);
	}

	int h_len = hp.size();
	for (int i = 1; i < h_len; i++) {
		h_dif.push_back(hp[i] - hp[i - 1]);
	}

	//가장 큰차이 가지는 두개 곱
	cout << *max_element(v_dif.begin(), v_dif.end()) * *max_element(h_dif.begin(), h_dif.end());
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}