#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void solution()
{
	int h, m, p;
	cin >> h >> m >> p;
	h += p / 60;
	m += p % 60;
	if (m >= 60) h++;

	h = h % 24;
	m = m % 60;
	
	cout << h << " " << m;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}