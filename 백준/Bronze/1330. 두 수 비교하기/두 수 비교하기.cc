#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void solution()
{
	int a, b, answer;
	cin >> a >> b;
	
	if (a > b) cout << ">";
	else if (a < b) cout << "<";
	else cout << "==";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}