#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string>

using namespace std;

void solution()
{
	string str;
	cin >> str;

	int zero_cnt = 0;
	int one_cnt = 0;
	int len = str.length();
	char before = str[0];

	//시작점 체크
	if (before == '0') zero_cnt++;
	else one_cnt++;

	for (int i = 1; i < len; i++) {
		if (str[i] == '0' && str[i] != before) zero_cnt++;
		else if (str[i] == '1' && str[i] != before) one_cnt++;
		before = str[i];
	}

	cout << min(zero_cnt, one_cnt);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}