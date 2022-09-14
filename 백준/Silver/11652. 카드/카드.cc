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

#define p pair <string, int>

map <string, int> m;
vector <p> v;

//가장 많은 카드를 가진것이 중복이면, 작은값을 출력
//그것이 아니라면 가장 많이 가진값을 출력
bool cmp(const p p1, const p p2) {
	if (p1.second == p2.second) return stol(p1.first) < stol(p2.first);
	return p1.second > p2.second;
}

void solution()
{
	string input;
	int n;
	cin >> n;

	//map으로 해싱한다.
	for (int i = 0; i < n; i++) {
		cin >> input;
		m[input]++;
	}

	//map to vector
	for (auto& it : m) {
		v.push_back(it);
	}

	sort(v.begin(), v.end(), cmp);

	cout << v[0].first;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}