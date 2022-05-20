#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <cmath>

using namespace std;

void solution()
{
	string str;
	cin >> str;

	//set은 중복을 허용하지 않는다.
	//set의 크기를 출력하면 정답인것
	set <string> s;

	string temp;
	int size = str.length();

	//ababc
	//모든 경우에 대해 찾는다.
	//a, ab, aba, abab, ababc -> b, ba, ...
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			temp += str[j];
			s.insert(temp);
		}
		temp = "";
	}

	cout << s.size();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}