#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <map>

using namespace std;

bool cmp(const int a, const int b) {
	return a > b;
}

void solution()
{
	vector <int> v;
	string str;

	cin >> str;
	int len = str.length();

	for (int i = 0; i < len; i++) {
		int n = str[i] - '0';
		v.push_back(n);
	}

	//내림차순
	sort(v.begin(), v.end(), cmp);

	//0이 너무 많으므로 문자열로 처리해야한다
	string res;
	int size = v.size();
	int cnt = 0;

	//문자열 이어 붙이기
	for (int i = 0; i < size; i++) {
		res += v[i] + '0';
		cnt += v[i];
	}

	//끝자리가 0(10의배수), 모든 숫자의 합이 3의 배수이면 30의 배수
	if (res[size - 1] == '0' && cnt % 3 == 0) cout << res;
	else cout << -1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}