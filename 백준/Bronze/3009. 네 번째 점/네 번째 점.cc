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
	int arr1[1005] = { 0 };
	int arr2[1005] = { 0 };
	int x1, y1, x2, y2, x3, y3;

	cin >> x1 >> y1;
	arr1[x1]++; arr2[y1]++;
	cin >> x2 >> y2;
	arr1[x2]++; arr2[y2]++;
	cin >> x3 >> y3;

	if (arr1[x3] == 0) cout << x3 << " ";
	else x2 == x3 ? cout << x1 << " " : cout << x2 << " ";
	if (arr2[y3] == 0) cout << y3;
	else y2 == y3 ? cout << y1 : cout << y2;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}