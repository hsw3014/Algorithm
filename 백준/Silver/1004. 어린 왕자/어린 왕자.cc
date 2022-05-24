#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void solution()
{
	int t, n;
	int x1, y1, x2, y2, cx, cy, r;
	double d1, d2;

	cin >> t;
	for (int i = 0; i < t; i++) {
		int go_out = 0; int go_in = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> cx >> cy >> r;
			d1 = sqrt((cx - x1) * (cx - x1) + (cy - y1) * (cy - y1));	//출발점과의 거리
			d2 = sqrt((cx - x2) * (cx - x2) + (cy - y2) * (cy - y2));	//도착점과의 거리

			//출발점, 도착점이 같은 원 안에 같이있거나 밖에있으면 0
			//서로 다른 원에 존재하면 무조건 진입/이탈이 1번은 발생
			//출발점이 원 내부에있거나, 도착점이 원 내부에 있을 수 있음(2가지)
			if (d1 < r && r < d2) go_out++;
			if (d2 < r && r < d1) go_in++;
		}
		cout << go_in + go_out << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}