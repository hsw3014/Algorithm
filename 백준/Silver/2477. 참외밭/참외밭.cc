#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solution()
{
	int before, before_length;
	int n, d, l;
	int h = 0, w = 0;
	int smallrect = -1;
	int dx[5] = { 0 };
	//반시계를 이루는 순서
	dx[1] = 4;
	dx[4] = 2;
	dx[2] = 3;
	dx[3] = 1;

	vector < pair < int, int > > v;
	cin >> n;
	for (int i = 0; i < 6; i++) {
		cin >> d >> l;
		v.push_back({ d, l });			// { 방향, 길이 }
		if (d == 1 || d == 2) w = max(w, l);	//큰 사각형 가로세로
		if (d == 3 || d == 4) h = max(h, l);

		if (i == 0) continue;

		before = v[i - 1].first;			//이전 방향과 길이
		before_length = v[i - 1].second;

		//반시계가 깨지면 작은 사각형임
		//마지막까지 작은사각형이 발견이안되면 첫값과 끝값으로 계산
		if (dx[before] != d) {
			smallrect = l * before_length;
		}
		else if (i == 5 && smallrect == -1) {
			smallrect = l * v[0].second;
		}
	}

	cout << (w * h - smallrect) * n;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}