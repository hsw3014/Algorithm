#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void solution()
{
	int a, b, answer;
	cin >> a >> b;
	answer = a * b;
	
	while (b > 0) {
		int c = b % 10;
		b /= 10;
		cout << a * c << endl;
	}

	cout << answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}