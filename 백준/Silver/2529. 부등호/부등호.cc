#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n;
long long mx, mn;
bool visit[15] = { 0 };
vector <char> v;

bool condition(int x, int y, char c)
{
	if (c == '>') return x > y;
	else return x < y;
}

void backtrack(string str, int idx)
{
	//꽉 찼으면 큰수, 작은수 설정
	if (str.size() == n + 1) {
		long long num = stoll(str);
		mx = max(mx, num);
		mn = min(mn, num);
		return;
	}
	//0~9 백트래킹
	for (int i = 0; i <= 9; i++) {
		int now = str.back() - '0';
		if (visit[i] == false && condition(now, i, v[idx])) {
			visit[i] = true;
			str.push_back(i + '0');
			backtrack(str, idx + 1);
			visit[i] = false;
			str.pop_back();
		}
	}
}

void solution()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	char c;
	string str;
	mx = -1;
	mn = 9999999999;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c;
		v.push_back(c);
	}

	for (int i = 0; i <= 9; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			str.push_back(i + '0');
			backtrack(str, 0);
			visit[i] = false;
			str.pop_back();
		}
	}
}

int main()
{
	//앞자리 0만 예외처리
	solution();
	cout << mx << endl;
	if (to_string(mx).size() > to_string(mn).size()) cout << "0";
	cout << mn;
}