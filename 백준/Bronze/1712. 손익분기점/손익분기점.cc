#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solution()
{
	int a, b, c;
	int answer = 0;
	cin >> a >> b >> c;
	if (b >= c) answer = -1;
	else {
		answer = (a / (c - b)) + 1;
	}

	cout << answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}