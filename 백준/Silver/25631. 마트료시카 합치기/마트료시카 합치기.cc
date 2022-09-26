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
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int ans = 0;
	vector <int> v;
	queue <int> q;

	int n, num;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end(), greater<>());

	//내림차순 큐
	for (int i = 0; i < n; i++) {
		q.push(v[i]);
	}

	int size = q.size();

	while (!q.empty()) {
		//첫번째 마트료시카(가장큼)
		int rem = q.front();
		q.pop();

		ans++;

		//마트료시카 채우기
		for (int i = 0; i < size - 1; i++) {
			int now = q.front();
			q.pop();

			//마트료시카 만족
			if (rem > now) {
				rem = now;
			}
			else {
				q.push(now);
			}
		}

		size = q.size();
	}

	cout << ans;

}

int main()
{
	solution();
}