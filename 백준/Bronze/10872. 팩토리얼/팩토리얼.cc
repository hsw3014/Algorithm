#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

void solution()
{
	int n;
	cin >> n;
	long long answer = 1;

	for (int i = 2; i <= n; i++) {
		answer *= i;
	}

	cout << answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}