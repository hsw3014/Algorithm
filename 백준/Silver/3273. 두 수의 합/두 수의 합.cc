#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string>

using namespace std;
vector <int> v;

void solution()
{
	int res = 0;

	int n, num, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	int left = 0;
	int right = n - 1;

	//두 포인터 위한 정렬
	sort(v.begin(), v.end());

	cin >> x;

	while (left < right) {
		int sum = v[left] + v[right];
		if (sum == x) {
			res++;
			left++;
		}
		else if (sum > x) {
			right--;
		}
		else {
			left++;
		}
	}

	cout << res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}