#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void solution()
{
	int arr[35] = { 0 };
	int n;
	for (int i = 0; i < 28; i++) {
		cin >> n;
		arr[n]++;
	}

	for (int i = 1; i <= 30; i++) {
		if (arr[i] == 0) cout << i << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}