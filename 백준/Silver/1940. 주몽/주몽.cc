#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <map>

using namespace std;

void solution()
{
	vector <int> v;
	int n, m, num;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	
	//두 포인터 정렬
	sort(v.begin(), v.end());

	int res = 0;
	int left = 0;
	int right = n - 1;

	while (left < right) {
		int sum = v[left] + v[right];

		//작으면 큰값으로
		if (sum < m) {
			left++;
		}
		else {
			right--;
		}

		if (sum == m) res++;
	}

	cout << res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}