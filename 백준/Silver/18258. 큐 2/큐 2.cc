#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void solution()
{
	queue < int > v;
	string cmd;
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> m;
			v.push(m);
		}
		else if (cmd == "front") {
			if (!v.empty())
				cout << v.front() << '\n';
			else
				cout << "-1\n";
		}
		else if (cmd == "back") {
			if (!v.empty())
				cout << v.back() << '\n';
			else
				cout << "-1\n";
		}
		else if (cmd == "size") {
			cout << v.size() << '\n';
		}
		else if (cmd == "empty") {
			if (v.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if (cmd == "pop") {
			if (v.empty()) cout << "-1\n";
			else {
				cout << v.front() << '\n';
				v.pop();
			}
		}
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}