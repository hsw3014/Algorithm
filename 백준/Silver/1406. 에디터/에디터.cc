#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

void solution()
{
	stack <char> s;
	stack <char> save;
	string str;
	string left, right;
	int n, size;
	char cmd, c;

	cin >> str;
	size = str.length();
	for (int i = 0; i < size; i++) {
		s.push(str[i]);
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == 'P') {
			cin >> c;
			s.push(c);
		}
		else if (cmd == 'L') {
			if (!s.empty()) {
				save.push(s.top());
				s.pop();
			}
		}
		else if (cmd == 'D') {
			if (!save.empty()) {
				s.push(save.top());
				save.pop();
			}
		}
		else if (cmd == 'B') {
			if (!s.empty()) s.pop();
		}
	}

	while (!s.empty()) {
		left += s.top();
		s.pop();
	}

	while (!save.empty()) {
		right += save.top();
		save.pop();
	}

	reverse(left.begin(), left.end());
	cout << left + right;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}