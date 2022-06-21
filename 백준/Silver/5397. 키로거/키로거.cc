#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

stack <char> s;
stack <char> save;

void solution()
{
	int idx = 0, n;
	string str;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string left, right;
		cin >> str;
		int size = str.length();
		for (int j = 0; j < size; j++) {
			if (str[j] == '-') {
				if (!s.empty()) s.pop();
			}
			else if (str[j] == '<') {
				if (!s.empty()) {
					save.push(s.top());
					s.pop();
				}
			}
			else if (str[j] == '>') {
				if (!save.empty()) {
					s.push(save.top());
					save.pop();
				}
			}
			else {
				s.push(str[j]);
			}
		}

		//두개 다 비워주기
		//거꾸로 출력됨(스택)
		//커서 우측은 뒤집을 필요가 없음
		while (!s.empty()) {
			left += s.top();
			s.pop();
		}

		int save_len = save.size();
		while (!save.empty()) {
			right += save.top();
			save.pop();
		}

		reverse(left.begin(), left.end());
		cout << left + right << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}