#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

struct cmp {
	bool operator()(int a, int b){
		if (abs(a) == abs(b)) return a > b;
		return abs(a) > abs(b);
	}
};

priority_queue <int, vector <int>, cmp > pq;

void solution()
{
	int n, num;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> num;
		if (num == 0) {
			if (pq.empty()) cout << "0\n";
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(num);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}