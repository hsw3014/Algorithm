#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

int arr[100005];

void solution()
{
	int n, num, before, dif;
	vector <char> s;
	stack <int> num_s;

	num_s.push(0);
	int cnt = 0;
	before = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		num = arr[i];
		
		while (true) {
			int top = num_s.top();
			//탑의 숫자가 낮으면 푸쉬, 찾은 숫자가 나오면 팝하면서 탈출
			//푸쉬할 수 없는데 팝할수도 없으면 실패
			if (top < num) {
				s.push_back('+');
				num_s.push(++cnt);
			}
			else {
				if (top == num) {
					s.push_back('-');
					num_s.pop();
					break;
				}
				else {
					cout << "NO";
					return;
				}
			}
		}
	}

	int size = s.size();
	for (int i = 0; i < size; i++) {
		cout << s[i] << '\n';
	}
}

int main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);

	solution();
}