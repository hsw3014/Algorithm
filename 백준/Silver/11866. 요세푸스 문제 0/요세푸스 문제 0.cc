#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

void solution()
{
	queue <int> q;
	vector <int> v;
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	while (!q.empty()) {
		for (int i = 0; i < k - 1; i++) {	//n-1번 이동시키고
			int temp = q.front();
			q.pop();
			q.push(temp);
		}
		v.push_back(q.front());	//담으면 완성
		q.pop();
	}

	int size = v.size();
	cout << "<";
	for (int i = 0; i < size - 1; i++) {
		cout << v[i] << ", ";
	}
	cout << v[size - 1] << ">";
}

int main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);

	solution();
}