#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <climits>

using namespace std;

priority_queue <long long, vector <long long>, greater<long long> > pq;

void solution()
{
	long long result = 0;
	int n;
	long long card;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> card;
		pq.push(card);
	}

	//vector sort를 시도하면 시간초과 우려(당장의 nlogn이 1억)
	//우선순위 큐 사용
	//가장 작은 두개의 카드뭉치를 뭉쳐야한다.

	//예외처리
	if (pq.size() == 1) {
		cout << "0";
		return;
	}

	long long a, b;

	while (true) {
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();

		pq.push(a + b);
		result += (a + b);

		if (pq.size() == 1) break;
	}

	cout << result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}