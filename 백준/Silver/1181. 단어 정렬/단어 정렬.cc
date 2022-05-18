#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

bool cmp(const pair <string, int>& a, const pair <string, int>& b)
{
	//문자열의 길이가 같으면 사전순, 다르면 문자열의 길이 기준 오름차순
	if (a.first.length() == b.first.length()) return a.first < b.first;
	return a.first.length() < b.first.length();
}

void solution()
{
	int n;
	string str;
	map < string, int > m;

	//key값을 문자열로 두어 중복입력을 방지
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		m[str] = i;
	}

	vector < pair <string, int> > v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);
	int size = v.size();

	for (int i = 0; i < size; i++) {
		cout << v[i].first << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}