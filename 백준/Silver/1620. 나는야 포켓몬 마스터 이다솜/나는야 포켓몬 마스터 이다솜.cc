#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

//문자열이 숫자인지 확인해야함
bool isNumber(string str)
{
	//str의 문자에 대해서
	for (char const& c : str) {
		//숫자가 하나라도 아닌게 있으면 false 리턴
		if (isdigit(c) == 0) return false;
	}
	return true;
}

void solution()
{
	int n, m;
	string str;
	map < string, int > mp1;
	map < int, string > mp2;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str;
		mp1[str] = i + 1;
		mp2[i + 1] = str;
	}

	for (int i = 0; i < m; i++) {
		int num = 0;
		cin >> str;
		if (isNumber(str)) num = stoi(str);
		if (1 <= num && num <= n) cout << mp2[num] << '\n';
		else cout << mp1[str] << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}