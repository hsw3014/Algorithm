#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void solution()
{
	int n, a;
	vector <int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}

	cout << *min_element(v.begin(), v.end()) << " " << *max_element(v.begin(), v.end());
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}