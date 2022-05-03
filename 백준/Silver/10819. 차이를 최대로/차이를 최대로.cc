#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution()
{
	int answer = -1;
	int N;
	int n;
	vector <int> v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> N;
		v.push_back(N);
	}

	sort(v.begin(), v.end());

	do {
		int sum = 0;
		int dif;
		for (int i = 0; i < n - 1; i++) {
			dif = v[i] - v[i + 1];
			sum += dif > 0 ? dif : dif * -1;
		}
		answer = max(answer, sum);
	} while (next_permutation(v.begin(), v.end()));

	return answer;
}

int main()
{
	cout << solution();
}