#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string solution()
{
	int n;
	int cnt = 1;
	int start = 665;
	string num;

	cin >> n;

	while (true) {
		start++;
		num = to_string(start);
		//666을 찾아서 존재하면, 리턴값은 npos라는 쓰레기값
		if (num.find("666") != string::npos) {
			if (cnt == n) {
				return num;
			}
			else {
				cnt++;
			}
		}
	}
}

int main()
{
	cout << solution();
}