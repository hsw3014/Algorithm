#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int r[100005];
int c[100005];

void solution()
{
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		cin >> r[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}

	//끝까지(n번째) 최소비용으로 도달하는 것이 최적
	//그럼 n-1번쨰 까지도 최적으로 이동할 것
	//다음에 주유하게 될 비용과 현재 주유하게 될 비용으로 최적을 계산(i, i+1 번째를 확인)
	//시작위치는 반드시 주유해야함

	long long result = 0;
	long long now_cost = c[0];

	result = now_cost * r[0];	//첫 최소 주유량

	for (int i = 1; i < n - 1; i++) {
		long long cost = c[i];
		int l = r[i];

		//이전에 주유했던 비용이 현재 주유 비용보다 크면 새로 주유함.
		//반대로 이전에 주유했던 비용이 더 싸면 이전 주유소에서 새로 주유함
		//즉, 계속 싼 가격대를 갱신해가면 된다.
		if (now_cost > cost) {
			now_cost = cost;
		}
		result += (long long)now_cost * l;
	}

	cout << result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}