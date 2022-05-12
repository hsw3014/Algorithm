#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int arr[10000005] = { 0 };

void solution()
{
	int m, n;
	int mid = sqrt(10000000);

	for (int i = 2; i <= 10000000; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= mid; i++) {
		if (arr[i] == 0) continue;
		for (int j = i * i; j <= 10000000; j += i) {
			arr[j] = 0;
		}
	}

	cin >> n;
	for (int i = 2; i <= 10000000; i++) {
		if (arr[i] != 0) {	//가장 작은 소수부터 시작
			while (n % arr[i] == 0) {
				cout << arr[i] << endl;
				n /= arr[i];
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solution();
}