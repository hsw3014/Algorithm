#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <set>

using namespace std;

int arr[6] = { 1, 1, 2, 2, 2, 8 };

void solution()
{
	int num;
	for (int i = 0; i < 6; i++) {
		cin >> num;
		cout << arr[i] - num << " ";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}