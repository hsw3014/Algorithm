#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void solution()
{
	int w, h, x, y, p, a, b, r, rx1, ry1, rx2, ry2;
	int answer = 0;
	double d1, d2;
	cin >> w >> h >> x >> y >> p;
	r = h / 2;
	rx1 = x, ry1 = y + r;
	rx2 = x + w, ry2 = y + r;

	for (int i = 0; i < p; i++) {
		cin >> a >> b;
		d1 = sqrt((rx1 - a) * (rx1 - a) + (ry1 - b) * (ry1 - b));
		d2 = sqrt((rx2 - a) * (rx2 - a) + (ry2 - b) * (ry2 - b));

		//왼쪽원
		if (a <= rx1 && d1 <= r) {
			answer++;
		}
		//오른쪽원
		else if (a >= rx2 && d2 <= r) {
			answer++;
		}
		//사각형
		else if ((x <= a && a <= x + w) && (y <= b && b <= y + h)) {
			answer++;
		}
	}

	cout << answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}