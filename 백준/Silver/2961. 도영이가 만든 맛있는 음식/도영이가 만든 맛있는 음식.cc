#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string>

using namespace std;

int s[5000];	//비트마스킹 인덱스
int b[5000];
int res = 1000000000;

void solution()
{
	int n;
	int mask = 1;

	cin >> n;

	//비트마스킹 인덱스에 맞추어 채움
	for (int i = 0; i < n; i++) {
		cin >> s[1 << i] >> b[1 << i];
	}

	int border = (1 << n) - 1;

	//mask 브루트포스
	while (mask <= border) {
		int s_mul = 1;
		int b_sum = 0;
		//모든 비트 확인시작
		for (int i = 0; i < n; i++) {
			int idx = (1 << i);	//0~n비트
			//&연산하여 재료를 사용하는 지 확인
			if ((mask & idx) > 0) {
				s_mul *= s[idx];
				b_sum += b[idx];
			}
		}

		//차이가 가장 작은것이 정답
		res = min(res, abs(s_mul - b_sum));
		mask++;
	}

	cout << res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}