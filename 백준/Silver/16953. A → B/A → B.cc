#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <climits>

using namespace std;

typedef struct entry {
	string str;
	int cnt;
};

queue <entry> q;

void solution()
{
	string a, b;
	long long num_a, num_b;
	cin >> a >> b;
	
	num_b = stol(b);
	q.push({a, 1});

	//반드시 커지는 구조, bfs 진행
	while (!q.empty()) {
		string now = q.front().str;
		int now_cnt = q.front().cnt;
		q.pop();

		num_a = stol(now);

		//숫자가 넘어가면 더 탐색할 이유 없음
		//같은 숫자면 종료
		if (num_a > num_b) continue;
		else if (num_a == num_b) {
			cout << now_cnt;
			return;
		}

		//2개의 연산, 2배와 1추가
		q.push({ to_string(num_a * 2), now_cnt + 1 });
		q.push({ now + '1', now_cnt + 1 });
	}

	//불가능
	cout << "-1";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}