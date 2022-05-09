#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int solution()
{
	priority_queue <int> big_q;
	priority_queue <int, vector <int>, greater<int> > sml_q;
	int n, a, b;
	int answer = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a; sml_q.push(a);
	}

	for (int i = 0; i < n; i++) {
		cin >> b; big_q.push(b);
	}

	while (!sml_q.empty()) {
		answer += (big_q.top() * sml_q.top());
		big_q.pop(); sml_q.pop();
	}

	return answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cout << solution();
}