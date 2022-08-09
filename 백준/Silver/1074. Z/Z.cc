#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int n, r, c;

void solution()
{
	cin >> n >> r >> c;
	//n은 2의 n승

	int result = 0;

	int all = (1 << (n + n));
	int h = (1 << n) - 1;
	int v = h;
	int x = 0;
	int y = 0;

	while (!(x == r && y == c)) {
		//절반을 기점으로 아래에있는지, 위에있는지
		// 1. 가로경계선 기점
		//아래에 있을 경우 전체 개수의 절반만큼 시행횟수 증가
		if (r > x + (h / 2)) {
			result += (all / 2);
			x += (h / 2) + 1;
		}
		
		h /= 2;
		all /= 2;
		// 2. 세로 경계선 기점
		//오른쪽에 있을 경우
		if (c > y + (v / 2)) {
			result += (all / 2);
			y += (v / 2) + 1;
		}

		v /= 2;
		all /= 2;
	}

	cout << result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}