#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <set>

using namespace std;

int n, m;
vector <int> v;
vector <int> r;
set < vector <int> > s;	//중복을 허용하지 않는 set을 사용
bool visit[10] = { false };

void backtrack()
{
	int size = r.size();

	//m개를 모두 골랐을 경우
	if (size == m) {
		auto check = s.insert(r);	//set에 삽입을 시도한다
		if (check.second) {	//삽입이 정상적으로 되면 중복이 아니므로 출력
			for (int i = 0; i < size; i++) {
				cout << r[i] << " ";
			}
			cout << '\n';
		}
		return;
	}

	//삽입이 안되면 중복이다. 계속 탐색
	for (int i = 0; i < n; i++) {
		if (visit[i] == false) {
			r.push_back(v[i]);
			visit[i] = true;
			backtrack();
			r.pop_back();
			visit[i] = false;
		}
	}
}

void solution()
{
	int num;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	int size = v.size();

	for (int i = 0; i < size; i++) {
		if (visit[i] == false) {
			r.push_back(v[i]);
			visit[i] = true;
			backtrack();
			r.pop_back();
			visit[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}