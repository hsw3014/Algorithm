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

void solution()
{
	//중복제거특화 집합, less로 오름차순
	set <int, less <int> > s;
	int n, num;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		s.insert(num);
	}
	
	//집합 순서대로 출력
	for (auto it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}