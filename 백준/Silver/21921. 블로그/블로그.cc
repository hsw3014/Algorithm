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

void solution()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, x, num;
	int res = 0;
	int cnt = 0;
	int sum[250005] = { 0 };
	
	cin >> n >> x;

	//누적합
	for (int i = 1; i <= n; i++) {
		cin >> num;
		sum[i] = sum[i - 1] + num;
	}

	//슬라이딩 윈도우
	for (int i = 1; i <= n - x + 1; i++) {
		int sub_sum = sum[i + x - 1] - sum[i - 1];

		//최대 인원 갱신
		if (res <= sub_sum) {
			//같은 일자 카운트, 새로 갱신되면 처음부터 다시셈
			if (res == sub_sum) {
				cnt++;
			}
			else {
				cnt = 1;
				res = sub_sum;
			}
		}
	}

	if (res == 0) {
		cout << "SAD";
	}
	else {
		cout << res << '\n' << cnt;
	}
}

int main()
{
	solution();
}