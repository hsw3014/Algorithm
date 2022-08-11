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
	string str1;
	string str2;

	//getline을 통해 공백문자를 포함하여 입력받는다
	//기본적으로 cin을 쓰면 개행이 입력버퍼에 남지만 getline은 개행까지 가져가서 괜찮다.
	//cin을 연속해서 써야할 경우 cin.ignore()로 개행을 비울 필요가 있을때가 존재한다
	getline(cin, str1);
	getline(cin, str2);

	int piv;
	int res = 0;
	int len = str2.length();

	while (true) {
		//못찾으면 아웃
		piv = str1.find(str2);
		if (piv == string::npos) break;

		//찾은부분 제거
		str1.erase(str1.begin(), str1.begin() + piv + len);
		res++;
	}

	cout << res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}