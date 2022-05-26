#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void solution()
{
	int n, k;
	cin >> n >> k;
	long long answer = 1;
	for (int i = 0; i < k; i++) {
		answer *= n - i;
	}
	for (int i = 0; i < k; i++) {
		answer /= i + 1;
	}
	cout << answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}