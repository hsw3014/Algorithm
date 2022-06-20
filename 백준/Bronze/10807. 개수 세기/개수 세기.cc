#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void solution()
{
	int n, num;
	int arr[205] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr[num + 100]++;
	}

	cin >> num;
	cout << arr[num + 100];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}