#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <map>

using namespace std;

#define p pair <int, int>

map <int, p> m;	//입력받은 번호에 따른 좌표 저장

int right_diag[6][6] = { 0 };
int cx[6] = { 0 };	//가로 동그라미개수(배열별로)
int cy[6] = { 0 };	//세로 동그라미개수(배열별로)

void solution()
{
	int num;
	int ld_cnt = 0;
	int rd_cnt = 0;

	//입력받은 번호별로 좌표 저장
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> num;
			m.insert({ num, { i, j } });
		}
	}

	//오른쪽 대각선만 예외
	right_diag[1][5] = 1;
	right_diag[2][4] = 1;
	right_diag[3][3] = 1;
	right_diag[4][2] = 1;
	right_diag[5][1] = 1;

	int res = 0;

	//번호 호명
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> num;

			//호명된 번호의 좌표
			int x = m[num].first;
			int y = m[num].second;

			//각 좌표별로 카운트 업
			cx[x]++;
			cy[y]++;

			//대각선
			if (x == y) ld_cnt++;
			if (right_diag[x][y] == 1) rd_cnt++;

			//개수 확인
			if (cx[x] == 5) res++;
			if (cy[y] == 5) res++;

			//대각선은 1번만씀
			if (ld_cnt == 5) {
				res++;
				ld_cnt = 0;
			}
			if (rd_cnt == 5) {
				res++;
				rd_cnt = 0;
			}

			//현재 몇빙고?
			if (res >= 3) {
				cout << (i - 1) * 5 + j;
				return;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}