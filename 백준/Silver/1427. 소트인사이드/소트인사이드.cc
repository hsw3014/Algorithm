#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

void solution()
{
	vector <int> v;
	int n;
	cin >> n;
	while (n != 0) {
		v.push_back(n % 10);
		n /= 10;
	}

	sort(v.begin(), v.end());
	int size = v.size();
	for (int i = size - 1; i >= 0; i--) {
		cout << v[i];
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}