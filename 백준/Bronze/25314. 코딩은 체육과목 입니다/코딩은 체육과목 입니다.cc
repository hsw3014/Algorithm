#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <climits>

using namespace std;

void solution()
{
	int n;
	cin >> n;
	int rest = n / 4;
	for (int i = 0; i < rest; i++) {
		cout << "long ";
	}
	cout << "int";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}