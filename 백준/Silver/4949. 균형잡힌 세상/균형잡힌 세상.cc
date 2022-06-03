#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

void solution()
{
	stack <char> s;
	char c;
	int len = 0;
	bool flag = true;
	while (true) {
		scanf("%c", &c);

		//개행문자 스킵
		if (c == '\n') continue;
		//탈출조건. 단독 .
		if (c == '.' && len == 0) break;

		//온점이오면 처리, 출력, 스택 비우기, 길이 0으로 초기화
		if (c == '.') {
			if (!s.empty()) flag = false;	//스택에 괄호가 들어있으면 균형잡히지 않음

			if (flag) printf("yes\n");
			else printf("no\n");
			flag = true;
			len = 0;
			while (!s.empty()) s.pop();
		}
		else {
			if (c == '(' || c == '[') s.push(c);	//괄호넣기
			else if (c == ')' || c == ']') {
				if (!s.empty()) {
					if (s.top() == '(' && c == ')') {	//괄호빼기
						s.pop();
					}
					else if (s.top() == '[' && c == ']') {
						s.pop();
					}
					else {
						flag = false;
					}
				}
				else {
					flag = false;
				}
			}
			len++;
		}

	}
}

int main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);

	solution();
}