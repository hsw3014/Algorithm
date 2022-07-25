#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

vector <int> v;

void solution()
{
	int n, c, left, right, p, size, before;
	cin >> n >> c;
	for (int i = 1; i <= n; i++) {
		cin >> p;
		v.push_back(p);
	}

	//오름차순 정렬
	sort(v.begin(), v.end());

	left = 1;
	right = 1000000000;
	size = v.size();

	//이분탐색
	while (left <= right) {
		before = v[0];
		int mid = (left + right) / 2;	//최소 설치거리
		int cnt = 1;	//시작점은 무조건 넣는다.

		//집을 순회하며 몇개까지 설치할 수 있는지 확인
		for (int i = 1; i < size && cnt < c; i++) {
			if (v[i] - before >= mid) {
				cnt++;
				before = v[i];
			}
		}

		//다 설치할 수 있었음 -> 설치거리 더 늘리면 됌
		if (cnt == c) {
			left = mid + 1;
		}
		//다 설치할 수 없었음 -> 설치거리 더 줄이면 됌
		else {
			right = mid - 1;
		}
	}
	cout << left - 1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}