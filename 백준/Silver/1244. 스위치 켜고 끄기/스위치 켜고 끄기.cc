#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string>

using namespace std;

int arr[105] = { 0 };
int n, m;

void solution()
{
	int sex, num;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	//양쪽끝 대칭도아니고 스위치도 아님
	arr[0] = -1;
	arr[n + 1] = -2;

	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> sex >> num;

		//1은 남자(배수), 2는 여자(대칭)
		if (sex == 1) {
			int all = num;
			while (all <= n) {
				if (arr[all] == 1) arr[all] = 0;
				else if (arr[all] == 0) arr[all] = 1;
				all += num;
			}
		}
		else if (sex == 2) {
			int left = num;
			int right = num;
			while ((left > 0 && right <= n) && arr[left] == arr[right]) {
				left--;
				right++;
			}

			//양쪽끝 보정
			left++;
			right--;

			//대칭범위만큼 변경
			for (; left <= right; left++) {
				if (arr[left] == 1) arr[left] = 0;
				else if (arr[left] == 0) arr[left] = 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << arr[i] << " ";
		if (i % 20 == 0) cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}