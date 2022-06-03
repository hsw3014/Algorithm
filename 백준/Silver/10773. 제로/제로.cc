#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

void solution()
{
	int k, n;
	int sum = 0;
	stack <int> s;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> n;
		if (n == 0) s.pop();
		else s.push(n);
	}

	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}

	cout << sum;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}