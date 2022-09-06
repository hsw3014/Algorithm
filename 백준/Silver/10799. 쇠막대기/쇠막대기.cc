#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <stack>

using namespace std;

void solution()
{
	string str;
	cin >> str;

	int answer = 0;
	int cnt = 1;
	int rest = 0;
	char before;
	int len = str.length();
	
	//초기작업
	before = str[0];

	for (int i = 1; i < len; i++) {
		char now = str[i];

		//레이저커팅
		//1을 빼는 이유는 철판이 아니라 레이저였으므로
		if (before == '(' && now == ')') {
			answer += (--cnt);
		}
		//철판의 끝이 잘림
		else if (now == ')') {
			answer++;
			cnt--;
		}
		//새 철판이 놓임
		else {
			cnt++;
		}

		//이전 기억
		before = now;
	}

	cout << answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}