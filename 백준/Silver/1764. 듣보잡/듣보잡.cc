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
	int answer = 0;
	int n, m;
	string str;
	map < string, int > mp1;
	vector < string > v;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str;
		mp1[str] = 1;
	}

	for (int i = 0; i < m; i++) {
		cin >> str;
		if (mp1[str] == 1) {
			answer++;
			v.push_back(str);
		}
	}

	//사전순 정렬
	int size = v.size();
	sort(v.begin(), v.end(), [](string& a, string& b) { return a < b; });
	cout << answer << '\n';
	for (int i = 0; i < size; i++) {
		cout << v[i] << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}