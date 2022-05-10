#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void solution()
{
	int x, y;
	cin >> x >> y;
	if (x < 0 && y < 0) cout << "3";
	else if (x < 0) cout << "2";
	else if (y < 0) cout << "4";
	else cout << "1";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}