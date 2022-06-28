#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

//우선순위 큐 비교연산자 사용 방법
struct cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};

void solution()
{
	priority_queue < int, vector <int>, cmp > q;
	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == 0) {
			if (q.empty()) cout << "0\n";
			else {
				cout << q.top() << '\n';
				q.pop();
			}
		}
		else {
			q.push(num);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}