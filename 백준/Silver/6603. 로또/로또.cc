#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

vector <int> v;
vector <int> vv;
int num, n;
bool visit[15] = { 0 };

void backtrack(int idx)
{
	//출력
	if (vv.size() == 6) {
		for (int i = 0; i < 6; i++) {
			cout << vv[i] << " ";
		}
		cout << '\n';
	}
	//탐색
	else {
		for (int i = idx; i < num; i++) {
			if (visit[i] == false) {
				visit[i] = true;
				vv.push_back(v[i]);
				backtrack(i);
				visit[i] = false;
				vv.pop_back();
			}
		}
	}
}

void solution()
{
	while (true) {
		cin >> num;
		if (num == 0) return;

		while (!v.empty()) v.pop_back();
		while (!vv.empty()) vv.pop_back();

		for (int i = 0; i < num; i++) {
			cin >> n;
			visit[i] = false;
			v.push_back(n);
		}

		//입력은 오름차순으로 주어진다.

		for (int i = 0; i < num; i++) {
			if (visit[i] == false) {
				visit[i] = true;
				vv.push_back(v[i]);
				backtrack(i);
				visit[i] = false;
				vv.pop_back();
			}
		}
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}