#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void solution()
{
	string a, b;
	vector <int> v;
	int piv = 0;
	int a_end, b_end, s, rest;

	cin >> a >> b;
	while (!a.empty() || !b.empty()) {
		//끝자리 하나씩, 비어있으면 0처리
		if (!a.empty()) a_end = a.back() - '0'; else a_end = 0;
		if (!b.empty()) b_end = b.back() - '0'; else b_end = 0;
		s = a_end + b_end + piv;
		if (s > 9) piv = 1;
		else piv = 0;
		rest = s % 10;

		//끝자리 계산 후 푸쉬, 각 문자열 끝자리는 제거
		v.push_back(rest);
		if(!a.empty()) a.erase(a.end() - 1, a.end());
		if(!b.empty()) b.erase(b.end() - 1, b.end());
	}

	//가장 큰수자리 예외처리
	if (piv == 1) v.push_back(1);

	int size = v.size();
	for (int i = size - 1; i >= 0; i--) {
		cout << v[i];
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}