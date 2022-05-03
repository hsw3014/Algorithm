#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution()
{
	int answer = 0;
	int E, S, M;

	cin >> E >> S >> M;

	int e = 0; int s = 0; int m = 0;

	while (true) {
		answer++;
		e++; s++; m++;
		if (e > 15) e = 1; if (s > 28) s = 1; if (m > 19) m = 1;
		if (e == E && s == S && m == M) return answer;
	}
}

int main()
{
	cout << solution();
}