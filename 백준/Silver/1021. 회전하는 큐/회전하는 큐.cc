#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution()
{
	deque <int> dq;
	int n, m;
	int arr[55];
	int answer = 0;
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		dq.push_back(i + 1);
	}

	for (int i = 0; i < m; i++) {
		int now = arr[i];
		int front = dq.front();
		int size = dq.size();
		int mid = size / 2;
		int idx = 0;

		if (now == front) dq.pop_front();	//1번 시행
		else {
			//위치 찾아 가장 가까운쪽으로 2 or 3번 시행
			for (int j = 1; j < size; j++) {
				if (dq[j] == now) {
					idx = j;
					break;
				}
			}

			//왼쪽이 빠름
			if (idx <= mid) {
				for (int j = 0; j < idx; j++) {
					int temp = dq.front();
					dq.pop_front();
					dq.push_back(temp);
					answer++;
				}
			}
			else {
				//오른쪽이 빠름
				for (int j = size - 1; j >= idx; j--) {
					int temp = dq.back();
					dq.pop_back();
					dq.push_front(temp);
					answer++;
				}
			}

			//최종적으로 제거
			dq.pop_front();
		}
	}

	return answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cout << solution();
}