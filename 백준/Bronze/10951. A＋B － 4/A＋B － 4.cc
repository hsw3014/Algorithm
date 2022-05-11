#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void solution()
{
	int a, b;
	while (!(cin >> a >> b).eof()) {
		cout << a + b << endl;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}