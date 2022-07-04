#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

void solution()
{
	double a, b, c;
	cin >> a >> b;
	c = a - (a * b / 100);
	if (c >= 100) cout << 0;
	else cout << "1";

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}