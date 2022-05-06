#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int solution()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int answer = -1;
	int n, m;
	int card[105];

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				int sum = card[i] + card[j] + card[k];
				if (sum <= m) answer = max(answer, sum);
			}
		}
	}

	return answer;
}

int main()
{
	cout << solution();
}