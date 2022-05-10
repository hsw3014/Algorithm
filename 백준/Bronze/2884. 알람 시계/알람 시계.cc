#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void solution()
{
	int h, m;
	cin >> h >> m;
	h = m - 45 >= 0 ? h : --h;
	m = m - 45 >= 0 ? m - 45 : 60 - (45 - m);
	if (h < 0) h = 23;
	cout << h << " " << m;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}