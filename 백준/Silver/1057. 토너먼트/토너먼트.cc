#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int answer = 0;
	int n, x, y;
	cin >> n >> x >> y;
	x--; y--;
	
	while (true) {
		answer++;
		if (x == 0 && y == 0 || (x / 2 == y / 2)) break;
		x /= 2; y /= 2;
	}

	return answer;
}

int main()
{
	cout << solution();
}