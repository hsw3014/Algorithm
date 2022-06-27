#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void solution()
{
	long long result = 1;
	long long sum = 0;
	long long n;
	cin >> n;
	while (true) {
		sum += result;
		if (sum > n) break;
		result++;
	}
	cout << result - 1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}