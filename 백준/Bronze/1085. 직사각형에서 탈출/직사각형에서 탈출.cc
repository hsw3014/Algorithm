#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <cmath>

using namespace std;

void solution()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int answer = 1005;
	answer = min({abs(x - w), abs(y - h), abs(x), abs(y)});
	cout << answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}