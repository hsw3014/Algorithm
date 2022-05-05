#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void solution()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	int v[10];
	cin >> n;

	for (int i = 0; i < n; i++) {
		v[i] = i + 1;
	}
	
	do{
		for (int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}
		cout << '\n';
	} while (next_permutation(v, v + n));
}

int main()
{
	solution();
}