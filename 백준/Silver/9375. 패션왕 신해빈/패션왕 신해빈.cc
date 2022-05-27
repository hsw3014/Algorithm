#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

void solution()
{
	int t, n;
	string str1, str2;
	cin >> t;
	for (int i = 0; i < t; i++) {
		map < string, int > m;	//{ 의상종류(키), 이름 }
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> str1 >> str2;

			//해당 이름을 찾아서 없으면 m.end()를 가리킴
			//그럴경우 추가
			if (m.find(str2) == m.end()) {
				m[str2] = 1;
			}
			//이미 존재하면 값을 올려버림
			else {
				m[str2]++;
			}
		}

		int answer = 1;
		//모든 맵에 대해서 계산
		for (auto k : m) {
			answer *= (k.second + 1);
		}
		answer--;
		cout << answer << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}