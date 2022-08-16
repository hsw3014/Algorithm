#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string>

using namespace std;

#define p pair <int, int>
int n, m, t_size;
int res = 987654321;

vector <p> city;
vector <p> chicken;
vector <p> temp;

int arr[55][55] = { 0 };

void dfs(int idx, int cnt)
{
	//예외처리(더이상 고를 수 없음)
	if (idx > t_size) return;

	//치킨집 다 골랐음
	if (cnt == m) {
		int c_size = city.size();
		int k_size = chicken.size();
		int sum_len = 0;
		//모든 집에 대해서 선택된 치킨집과 거리 계산, 갱신
		for (int i = 0; i < c_size; i++) {
			int min_len = 987654321;
			int c_x = city[i].first;
			int c_y = city[i].second;

			for (int j = 0; j < k_size; j++) {
				int k_x = chicken[j].first;
				int k_y = chicken[j].second;

				//집에서 모든 치킨집과의 거리중 최소값(치킨거리)
				min_len = min(min_len, abs(k_x - c_x) + abs(k_y - c_y));
			}

			//모든 집의 치킨거리의 합(도시의 치킨거리)
			sum_len += min_len;
		}

		//도시의 치킨거리 갱신
		res = min(res, sum_len);
	}
	else {
		//m개 만족할 때 까지 치킨집 추가하거나 제거
		for (int i = idx; i < t_size; i++) {
			chicken.push_back({ temp[i].first, temp[i].second });
			dfs(i + 1, cnt + 1);
			chicken.pop_back();
			dfs(i + 1, cnt);
		}
	}
}

void solution()
{
	cin >> n >> m;

	//도시, 치킨집 별도 저장
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				city.push_back({ i, j });
			}
			else if (arr[i][j] == 2) {
				temp.push_back({ i, j });
			}
		}
	}

	//해당 치킨집을 살리거나 폐업시킨다.
	t_size = temp.size();
	for (int i = 0; i < t_size; i++) {
		chicken.push_back({ temp[i].first, temp[i].second });
		dfs(i + 1, 1);
		chicken.pop_back();
		dfs(i + 1, 0);
	}

	cout << res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}