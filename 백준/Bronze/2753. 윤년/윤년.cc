#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void solution()
{
	int year;
	cin >> year;

	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) cout << "1";
	else cout << "0";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}