#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int get_gcd(int a, int b)
{
	while (true) {
		int c = a % b;
		if (c == 0) return b;
		a = b;
		b = c;
	}
}

void solution()
{
	int n;
	int arr[105];
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i == 0) continue;

		int front = arr[0];
		int back = arr[i];

		int gcd = get_gcd(front, back);
		cout << front / gcd << '/' << back / gcd << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}