#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <climits>

using namespace std;

vector <int> v;

bool cmp(const int& a, const int& b) {
	return a > b;
}

void solution()
{
	int n, m, b, num;
	int result_h, result_t, h, t;
	cin >> n >> m >> b;
	int mul = n * m;

	for (int i = 0; i < mul; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end(), cmp);

	int temp_b;
	result_t = 987654321;
	result_h = -1;

	//최대 높이부터 하나씩 만들어보기
	for (int i = 256; i >= 0; i--) {
		t = 0; temp_b = b;
		for (int j = 0; j < mul; j++) {
			//쌓기 - 1초
			if (v[j] < i) {
				if (temp_b >= i - v[j]) {
					temp_b -= (i - v[j]);
					t += (i - v[j]);
				}
				else {
					//불가능
					t = 987654321;
					break;
				}
			}
			//깎기 - 2초
			else if (v[j] > i) {
				temp_b += (v[j] - i);
				t += (v[j] - i) * 2;
			}
		}

		//갱신, 등호 안달아서 최대 높이 출력
		if (t < result_t) {
			result_t = t;
			result_h = i;
		}
	}

	cout << result_t << " " << result_h;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}