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

#define BIG 2000000000

void solution()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	long long n, k, num;

	vector <long long> v;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	long long s = v[0];
	long long e = BIG + 1;

	while (s + 1 < e) {
		long long mid = (s + e) / 2;
		long long tk = k;

		bool possible = true;
		//시행
		for (auto it : v) {
			long long dif = mid - it;

			tk -= dif;

			//해당 레벨 만들 수 없음
			if (tk < 0) {
				possible = false;
				break;
			}
		}

		//해당 레벨을 못만듬 -> 너무 높은 레벨, 반대는 너무 낮은 레벨
		if (!possible) {
			e = mid;
		}
		else {
			s = mid;
		}
	}

	cout << s;
}

int main()
{
	solution();
}