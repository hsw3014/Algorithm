#include <iostream>
#include <cstdio>
#include <cstring>
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
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	map <char, int> map;
	string str;
	string left;
	char mid = '\0';
	char now;

	cin >> str;
	int len = str.length();
	for (int i = 0; i < len; i++) {
		now = str[i];
		map[now]++;
	}

	int half;
	int cnt = 0;

	//ABCD.. 순회하면서 그리디하게 접근
	//1개짜리가 2개이상이면 실패
	for (char c = 'A'; c <= 'Z'; c++) {
		half = map[c] / 2;
		map[c] %= 2;

		if (map[c] == 1) {
			if (cnt == 0) mid = c;
			cnt++;
		}

		if (cnt >= 2) {
			cout << "I'm Sorry Hansoo";
			return;
		}

		//팰린드롬 만들기
		for (int j = 0; j < half; j++) {
			left += c;
		}
	}

	cout << left;
	if (mid != '\0') cout << mid;
	reverse(left.begin(), left.end());
	cout << left;
}

int main()
{
	solution();
}