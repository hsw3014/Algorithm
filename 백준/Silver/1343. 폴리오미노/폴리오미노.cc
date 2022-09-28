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

	string str;
	string a = "AAAA";
	string b = "BB";

	cin >> str;

	//검색
	auto idx = str.find("XXXX");
	while(idx != string::npos) {
		str.replace(idx, 4, a);
		idx = str.find("XXXX");
	}

	idx = str.find("XX");
	while (idx != string::npos) {
		str.replace(idx, 2, b);
		idx = str.find("XX");
	}

	idx = str.find('X');
	if (idx == string::npos) cout << str;
	else cout << -1;
}

int main()
{
	solution();
}