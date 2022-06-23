#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define M 1234567891
#define r 31

void solution()
{
	int l;
	long long result = 0, y;
	string str;

	cin >> l;
	cin >> str;

	for (int i = 0; i < l; i++) {
		y = 1;
		for (int j = 0; j < i; j++) {
			y = (y * r) % M;
		}
		y = ((str[i] - 'a' + 1) * y) % M;
		result = (result + y) % M;
	}

	cout << result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}