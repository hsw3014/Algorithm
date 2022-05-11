#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void solution()
{
	int answer = -1;
	int idx;
	int n;
	for (int i = 0; i < 9; i++) {
		cin >> n;
		if (n > answer) {
			idx = i + 1;
			answer = n;
		}
	}

	cout << answer << endl << idx;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}