#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int solution()
{
	int arr[1005] = { 0 };
	int n, num;
	int answer = 0;

	for (int i = 2; i <= 1000; i++) {
		arr[i] = i;
	}

	//제곱수이용해 소수판별
	int q = sqrt(1000);
	for (int i = 2; i <= q; i++) {
		if (arr[i] == 0) continue;
		else {
			//제곱수는 소수
			for (int j = i * i; j <= 1000; j += i) {
				arr[j] = 0;
			}
		}
	}
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (arr[num] > 0) answer++;
	}

	return answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cout << solution();
}