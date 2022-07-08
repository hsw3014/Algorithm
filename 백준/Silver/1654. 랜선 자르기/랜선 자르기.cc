#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <climits>

using namespace std;

int arr[10005];

void solution()
{
	int n, k;
	long long left = 0;
	long long right = INT_MAX;
	
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}

	//이분탐색
	while (left <= right) {
		int many = 0;
		long long mid = (left + right) / 2;

		for (int i = 0; i < k; i++) {
			many += arr[i] / mid;
		}

		//many가 너무 적으면 단위가 너무 큼 -> right가 작아짐
		//반대로 작으면 단위가 너무 작은것을 의미 -> left가 커짐
		//답이 맞더라도 최대값을 찾아야 한다.

		if (many < n) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	cout << right;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}