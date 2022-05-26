#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void solution()
{
	int n;
	cin >> n;
	cout << n / 5 + n / 25 + n / 125;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}