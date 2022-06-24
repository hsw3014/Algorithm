#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void solution()
{
	string str;
	while (true) {
		int c = true;
		cin >> str;
		if (str == "0") break;
		int size = str.length();
		for (int i = 0; i < size; i++) {
			if (i > size - i - 1) break;
			if (str[i] != str[size - i - 1]) {
				c = false;
				break;
			}
		}

		if (c) cout << "yes\n";
		else cout << "no\n";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}